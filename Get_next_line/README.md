# get_next_line
The purpose of this project is to code a function which reads content line by line on a file descriptor, with an editable buffer size.

## Grade
**115 / 100**
<br>
<br>
![Alt text](../images/rank115.png)

## Usage:
- You can edit the file to read in `main.c`

`fd = open("name_of_your_file", O_RDONLY);`
- Then execute :

 `clang -Wall -Wextra -Werror -D BUFFER_SIZE=256 get_next_line.c get_next_line_utils.c main.c; ./a.out`

## Dependencies :
* __clang__
* __make__