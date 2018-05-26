# AMAZE. A project for Linguagem de Programação I (LP I)

## Introduction

This programming project implements a simulation over the **SNAKE** game, but also adding obstacles, so it also a merge between the game **Snake** and a Maze, therefore, we shall have our ***SNAZE***.
Snake is either controlled by a client, or by a programmed ia, with the purpose to always get the apple.
###### Description of Amaze goes Here.

## Algorithms

Functions implemented for:

1. Recursively find the path to apple.
2. Functioning of Snake. Which means it's growing and movement.
3. c.

## TODO

- [ ] Create (functional) Class Maze.
- [ ] Create (functional) Class Snake.
- [ ] Code function to find Snake's path to apple.
- [ ] Code Snake's growing and movement.
- [ ] Make it usable for both client and I.A.
- [ ] Doxygen commentation.
- [ ] Cope function ....

## How to compile

First of all, obviously this repository is needed to work as desired, so we must to download this repo. As we know that ```git``` is a tremendous tool for any programmer, then we must have git installed.

It is also expected for user to have installed [doxygen](https://en.wikipedia.org/wiki/Doxygen) program. This will automatically generate documentation for code. Not a necessary package to compile and run program, but it is a tool to guide user through code functions. To install `doxygen` on UBUNTU, for example:

```bash
$ sudo apt-get install doxygen
```
To compile we will use a makefile, so compilations may be more dynamic and automatic.
```bash
# Using 'git clone' to clone this repo into desired directory:
$ git clone https://github.com/FelipeCRamos/amaze.git

# Enter repo:
$ cd snaze

# To compile the whole project insert 'make':
$ make

# To generate project documentation, insert 'make docs':
$ make docs

# To clean up all remaining trash data and files, such as the binary ones, insert 'make clean':
$ make clean
```

## How to execute

Now, we show how to run the program.
We made it able to generate the maze map either randomicly, or by receiving a file containg maze structure data.

To receive a file, it is needed to run program with 2 command arguments.
-  ***-f*** : It says to code that a file is being requested to run.
- ***[FILE_NAME]***: It tells code which file is this.

To generate random maze structure, run the executable with no arguments.

```bash
# To execute program, and create randomicly, simply run program:
$ ./snaze

# To execute program with maze received through file, run like this:
$ ./snaze -f <input_file_name>
```

### Example

Let's say you wish to randomic create the maze map, then you must use like:
```bash
$ ./snaze
```
It will create a total random maze structure.

Now, if you have a file containing maze data(let's consider this file as 'data/input_file.dat'), and is wished to run the code with this specified data, then code must be run as:
```bash
$ ./snaze -f data/input_file.dat
```
## GitHub Repository:

*https://github.com/FelipeCRamos/amaze*

## Authorship

Program developed by [_Daniel Guerra_](https://github.com/Codigos-de-Guerra) (*daniel.guerra13@hotmail.com*) and [_Felipe Ramos_](https://github.com/FelipeCRamos) (*felipe.da.costa_10@hotmail.com*), 2018.1

&copy; QuebraCódigos_Ltda, 2018.
