# Overview #

Three weeks into Month 3 and we have another project - **0x19. C - Stacks, Queues - LIFO, FIFO**. The goal of the project is to create an interpreter for Monty ByteCodes files.

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it.

### Repo Details ###
- **Date Created:** Tue Nov 14 2023.
- **Created By:** [William Inyam](https.//github.com/thecypherzen).
- **Project Timeline:**
- - **Released:** Tue Nov. 14, 2023 - 6am.
- - **1st Deadline:** Fri Nov. 17, 2023 - 6am.
- - **Duration:** 72 hrs.
- - **Month** 3, **Week** 3, **Day** 2.


# Project Instructios #
### Monty byte code files ###
- Files containing Monty byte codes usually have the <span style="color:maroon">.*m* extension</span>. Most of the industry uses this standard but it *is not* required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:
```
{
	maverix:monty$ cat -e bytecodes/000.m
	push 0$
	push 1$
	push 2$
	push 3$
					pall    $
	push 4$
		push 5    $
		push    6        $
	pall$
}
```
- Monty byte code files <span style="color: maroon">can contain blank lines (empty or made of spaces only)</span>, and any additional text after the opcode or its required argument is not taken into account:
```
{
	maverix:monty$ cat -e bytecodes/001.m
	push 0 Push 0 onto the stack$
	push 1 Push 1 onto the stack$
	$
	push 2$
	push 3$
					pall    $
	$
	$
							$
	push 4$
	$
		push 5    $
		push    6        $
	$
	pall This is the end of our program. Monty is awesome!$
	maverix:monty$
}
```
### The monty program ###
- Usage: monty file
where file is the path to the file containing Monty byte code
- - If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE.

- If, for any reason, it’s not possible to open the file, print the error message ==Error: Can't open file <file>==, followed by a new line, and exit with the status EXIT_FAILURE
- - where <file> is the name of the file

- If the file contains an invalid instruction, print the error message ==L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE:
- - where is the line number where the instruction appears.
- - Line numbers always start at 1

- The monty program runs the bytecodes line by line and stop if either:
- - it executed properly every line of the file
- - it finds an error in the file
- - an error occured

- If you can’t malloc anymore, print the error message <span style="color:maroon">Error: malloc failed</span>, followed by a new line, and exit with status EXIT_FAILURE.
- - You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …).


### Technologies ##
- All files written to be C-89 compatible and compiled with gcc 9.4.0 using the options <span style="color: maroon">-Wall -Werror -Wextra -pedantic -std=c89</span>.
- All shell scripts written in GNU bash 5.0.17(1)-release (x86_64-pc-linux-gnu).
- Code tested on Ubuntu 20.04 LTS.


### Files ###
- Here is a detailed list of all files in the repo and their description.

| SN | File | Description                                   |
|----|------|-----------------------------------------------|
| 1. | [monty.h](https://github.com/) |  General header file of all function prototypes and libraries. |
| 2. |   Pending   |    |
