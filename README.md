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
Bash
git clone [https://github.com/Leila4242/holbertonschool-simple_shell.git](https://github.com/Leila4242/holbertonschool-simple_shell.git)
cd holbertonschool-simple_shell


Compile the source code using the following flags:
Bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Usage
Interactive Mode
Run the executable:
Bash$ ./hsh
($) /bin/ls
hsh  main.c  shell.c  README.md
($) exit
$

Non-Interactive ModeBash
$echo "ls -l" | ./hsh$ cat commands.txt | ./hsh

## 📂 Project Structure
shell.h: The header file containing standard library includes, the extern char **environ declaration, and function prototypes.

main.c: The heart of the shell. Contains the entry point, string parsing logic, and the execution engine.

## Authors
Leyla Aliyeva - Leila4242

Anar Aghamaliyev - AnarAghamaliyev

---

