# Minishell

## Purpose

Minishell is a group project at 42 School. <br>
The goal of this project is to create a simple shell that behave like bash. <br>
I've done this project with Paco Coureau (pcoureau@student.42.fr)

## Grade
**100 / 100**
<br>
<br>
![Alt text](../images/rank100.png)



## Subject


We based our program on bash behavior.

__*Rules of project*__

__implement the following builtins:__

- `echo` and the `-n` option
- `cd` only with an absolute or relative path
- `pwd` without any options
- `export` without any options
- `unset` without any options
- `env` without any options or arguments
- `exit` without any options

__The function to be implemented in the project__

- Display a prompt while waiting for a new order.
-  Find and launch the correct executable (based on a PATH environment variable
or using an absolute path).
- `;` in the command line must separate the commands.
- `’`and `"` must work as in bash, except multiline.
- The `<`,`>` and `>>` redirects must work as in bash, except for
aggregations of fd.
-  Pipes redirections `|`.
- The environment variables ($ followed by characters) must work.
- `$?` variable.
- `ctrl-C`, `ctrl-D` and `ctrl- \` signals should have the same behavior.

This project is coded in C with our proper norm at 42.


## Usage

Run the Makefile with the `make all` command to compile all the files

Then run the executable `./minishell`


## Resources

  [bash reference manual](https://www.gnu.org/software/bash/manual/bash.pdf)