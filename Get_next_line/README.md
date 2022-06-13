# get_next_line
The purpose of this project is to code a function which reads content line by line, with an editable buffer size.

## Grade
115 / 100
<br>
![Alt text](../images/rank.png)

## Usage:
- You can edit the file to read in `main.c`
<br>

`fd = open("name_of_your_file", O_RDONLY);`
- Then execute :
 <br>

 `clang -Wall -Wextra -Werror -D BUFFER_SIZE=256 get_next_line.c get_next_line_utils.c main.c; ./a.out`

## Dépendances :
* __clang__
* __make__