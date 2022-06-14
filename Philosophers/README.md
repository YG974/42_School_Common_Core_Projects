# Philosophers
## Purpose
 Extract from the Project Subject :

> " In this project, you will learn the basics of threading a process. You will learn how to make threads. You will discover the mutex. "

This project is written in C and is designed to run on MacOS.
You will find 2 different programs :
- philo_one using multi-threading and mutexes
- philo_two using multi-threading and semaphores

The aim of this project is to practice multi-threading.
We have a group of philosophers around a table eating and thinking. Each philosopher have a fork but he needs two to eat, so he must take the fork of another philosopher.
The philosophers can't talk to each other, and if a philosopher doesn't eat for a certain amount of time, he will die.

## Grade
**100 / 100**
<br>
<br>
![Alt text](../images/rank100.png)
## Usage
 Execute `make all` to compile <br>
 Each program have it's own makefile. <br>
 Then execute: `./philo arg_1 arg_2 arg_3 arg_4 [arg_5]`

You can run a program with the following arguments:
 * arg_1 = Number of philosophers
 * arg_2 = Time to die
 * arg_3 = Time to eat
 * arg_4 = Time to sleep
 * arg_5 = Number of meals (optional)

Now you juste have to wait and see if one of them dies from hunger.
