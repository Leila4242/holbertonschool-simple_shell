#include "shell.h"

/**
 * free_args - Frees the array of strings
 * @args: The array to free
 */
void free_args(char **args)
{
	int i;

	if (!args)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}

/**
 * tokenize - Splits a string into tokens
 * @line: String to split
 * Return: Array of tokens
 */
char **tokenize(char *line)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (!tokens)
		return (NULL);
	token = strtok(line, " \n\t\r");
	while (token)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " \n\t\r");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
 * get_path - Finds the full path of a command
 * @cmd: Command to find
 * Return: Full path or NULL
 */
char *get_path(char *cmd)
{
	char *path, *path_cp, *tok, *file;
	struct stat st;
	int i;

	path = NULL;
	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}
	if (!path || path[0] == '\0')
		return (NULL);
	path_cp = strdup(path);
	if (!path_cp)
		return (NULL);
	tok = strtok(path_cp, ":");
	while (tok)
	{
		file = malloc(strlen(tok) + strlen(cmd) + 2);
		if (!file)
		{
			free(path_cp);
			return (NULL);
		}
		sprintf(file, "%s/%s", tok, cmd);
		if (stat(file, &st) == 0)
		{
			free(path_cp);
			return (file);
		}
		free(file);
		tok = strtok(NULL, ":");
	}
	free(path_cp);
	return (NULL);
}

/**
 * execute - Forks and executes the command
 * @args: Arguments
 * @argv: Main argv for error reporting
 * @count: Command count
 * Return: Exit status
 */
int execute(char **args, char **argv, int count)
{
	pid_t pid;
	int status;
	char *path;

	path = get_path(args[0]);
	if (!path)
	{
		fprintf(stderr, "%s: %d: %s: not found\n",
			argv[0], count, args[0]);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, environ) == -1)
		{
			perror("execve");
			free(path);
			exit(127);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		free(path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}

/**
 * main - Entry point for the shell
 * @ac: Arg count
 * @av: Arg vector
 * Return: Exit status of last command
 */
int main(int ac, char **av)
{
	char *line = NULL;
	size_t n = 0;
	char **args;
	int count = 0, i;
	int last_status = 0;

	(void)ac;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			exit(last_status);
		}
		count++;
		args = tokenize(line);
		if (args && args[0])
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(line);
				free_args(args);
				exit(last_status);
			}
			if (strcmp(args[0], "env") == 0)
			{
				for (i = 0; environ[i]; i++)
					printf("%s\n", environ[i]);
			}
			else
				last_status = execute(args, av, count);
		}
		free_args(args);
	}
	return (last_status);
}