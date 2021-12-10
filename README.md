<h1 align=center>
	<b>Get_next_line 1337's PROJECT : </b>
</h1>

---


<h4 align=center>
	Reading a line on a fd is way too tedious

</p>
<p align="center">
<img src="https://c.tenor.com/YSTuX1eo83gAAAAS/fist-mad.gif" width="300">
</p>

</h4>

<p align=center>
	In this repo you will find all the codes developed during the <i>get_next_line</i> 1337's project, both <b>mandatory</b>'s part and <b>bonus</b> part.
</p>

---

<div align=center>
<h2>
<img src=https://github.com/ablaamim/Get_Next_Line/blob/main/SRC/get_next_linem.png alt=ablaamim's 42Project Badge/>
</div>

---

<h3 align=center>
Mandatory
</h3>

> <i>Calling the function get_next_line in a loop will then allow you to read the text available on the file descriptor one line at a time until the end of it.
The function should return the line that has just been read. If there is nothing
else to read or if an error has occurred it should return NULL.</i>

<p align=center>

</p>

---

<h3 align=center>
Bonus
</h3>

> <i> To succeed get_next_line with a single static variable.
To be able to manage multiple file descriptors with your get_next_line. For
example, if the file descriptors 3, 4 and 5 are accessible for reading, then you can call get_next_line once on 3, once on 4, once again on 3 then once on 5 etc.
without losing the reading thread on each of the descriptors
</i>
<p align=center>

</p>

---

<h2>
The project
</h2>

### Header files

- [`get_next_line.h`](get_next_line.h)
- [`get_next_line_bonus.h`](get_next_line_bonus.h)

### Mandatory :

```
	MANDATORY ALGORITHM :

	GET_NEXT_LINE

	DESCRIPTION :
	Write a function which returns a line read from a
	file descriptor.

	RETURN VALUES :

	Read line: correct behavior.
	NULL: nothing else to read or an error occurred.
```

```
	FUNCTION : FT_IS_LINE

	DESCRIPTION :

	[ LINEAR SEARCH]
	This function checks if the string in the buffer contains a line.
	A line is defined by the '\n' character.

	RETURN VALUES :

	If the buffer contains a line, the function returns 1 [SUCCESS] ; otherwise, 
	the function returns 0 [FAILURE];

```

```

	FUNCTION : READ_FILE
	
	DESCRIPTION :

	This function reads a file descriptor with read(2) and checks if the read
	buffer has a line, if it doesn't have a line, the static_buffer is updated
	with the contents of the buffer.
	
	RETURN VALUES :

	When the function finds a line or EOF, it returns the get_line function,
	otherwise, if the read(2) function fails to read the file descriptor, the
	function will return NULL;

```

```
	FUNCTION : FT_UPDATE_BUFFER

	DESCRIPTION :

	This function updates the static_buffer with the buffer.
```

```
	GET_LINE :

	DESCRIPTION
	This function takes the line that contains in static_buffer, and checks
	if it has more content after the line, if it does, the function updates the
	static_buffer with that content.
	A line is defined by the '\n' character.

	RETURN VALUES
	If static_buffer contains a line, the function returns a pointer with that
	line; otherwise, the function returns a pointer to NULL;
```

- [`get_next_line`](get_next_line.c)

### MOSTLY LIBFT FUNCTIONS WITH SLIGHT MODIFICATIONS :))

- [`get_next_line_utils`](get_next_line_utils.c)

### Bonus

- [`get_next_line_bonus`](get_next_line_bonus.c)
- [`get_next_line_utils_bonus`](get_next_line_utils_bonus.c)

---
<h2>
Usage
</h2>

### Requirements

`get_next_line` requires *gcc* compiler and some standard libraries.

### Instructions

Clone this repository in your local computer:

```sh
git clone https://github.com/ablaamim/Get_Next_Line.git
```

To use the library in your code you will need to include the header:
```c
#include "get_next_line.h"
```
or
```c
#include "get_next_line_bonus.h"
```

To compile the program, use these flags:
> <b>Make sure to change the XX after BUFFER_SIZE to the buffer size you want the program to work with.</b>
```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=XX path/to/main_function.c path/to/get_next_line.c path/to/get_next_line_utils.c -I path/to/get_next_line.h 
```
---

</p>
<p align="center">
<img src="https://c.tenor.com/_1ZY0sOzXWcAAAAC/porky-pig-thats-all-folks.gif" width="450">
</p>

---
