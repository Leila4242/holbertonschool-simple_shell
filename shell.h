#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Function Prototypes */
char	**tokenize(char *line);
int	execute(char **args, char **argv, int count);
char	*get_path(char *cmd);
void	free_args(char **args);

#endif /* SHELL_H */
