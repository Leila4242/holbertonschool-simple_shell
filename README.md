# Simple Shell - (hsh) 🐚

A simple UNIX command interpreter developed as part of the Low-level programming & Algorithm track at ALX Software Engineering. This project is a functional recreation of the Thompson Shell (`sh`).

---

## Table of Contents
* [Description](#description)
* [Features](#features)
* [Requirements](#requirements)
* [Installation & Compilation](#installation--compilation)
* [Usage](#usage)
* [Project Files](#project-files)
* [Authors](#authors)

---

## Description
`hsh` is a command-line interface that acts as an intermediary between the user and the operating system kernel. It reads commands from standard input, parses them, and executes them by creating new processes.



## Features
* **Command Execution:** Executes binary files found in the `PATH` or via absolute/relative paths.
* **Interactive Mode:** Provides a prompt `($)` and waits for user input.
* **Non-Interactive Mode:** Can receive commands via pipes or redirects.
* **PATH Handling:** Automatically searches for commands in the directories listed in the `PATH` environment variable.
* **Built-in Commands:** Supports `exit` (to leave the shell) and `env` (to print the current environment).
* **Signal Handling:** Handles `Ctrl+C` (SIGINT) to prevent the shell from exiting unexpectedly.
* **Error Handling:** Mimics the error output of `/bin/sh`.

---

## Requirements
* **Operating System:** Ubuntu 20.04 LTS
* **Compiler:** `gcc`
* **C Standard:** `gnu89`
* **Style Guide:** [Betty Style](https://github.com/holbertonschool/Betty)

---

## Installation & Compilation
Clone this repository to your local machine:
```bash
git clone [https://github.com/Leila4242/holbertonschool-simple_shell.git](https://github.com/Leila4242/holbertonschool-simple_shell.git)
cd holbertonschool-simple_shell

Compile the source code using the following flags:Bashgcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
UsageInteractive ModeRun the executable:Bash$ ./hsh
($) /bin/ls
hsh  main.c  shell.c  README.md
($) exit
$

Non-Interactive ModeBash$echo "ls -l" | ./hsh$ cat commands.txt | ./hsh

Project FilesFileDescriptionmain.cEntry point of the shell, contains the main loop.shell.hHeader file containing function prototypes and structures.parser.cFunctions to tokenize and parse user input.executor.cHandles fork, execve, and wait logic.path.cLogic for searching commands within the PATH.builtins.cImplementation of exit and env.man_1_simple_shellCustom manual page for the shell.AuthorsYour Name - GitHubPartner Name - GitHub
---

