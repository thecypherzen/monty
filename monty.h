#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

typedef unsigned int u_int;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, u_int line_number);
} instruction_t;

/* monty macros and custom types  */
/**
 * struct monty_t - monty interpreter useful data
 * @fd: descriptor of file to read from
 * @opmode: mode of operation. Set by macros STACK and QUEUE
 * @stack_n: integer to be pushed to stack
 * @lineno: line number of current command
 * @stack: address of ptr to the monty_stack
 */
typedef struct monty_t
{
	int fd;
	int *opmode;
	int *stack_n;
	u_int *lineno;
	stack_t **stack;
} monty_t;

typedef void (*mf_type)(stack_t **, u_int);
extern monty_t mdata;

#define STACK 1 /* stack mode def */
#define QUEUE 2 /* queue mode def */
#define NOTFOUND 127
#define SIGSEGV -11
#define ENOTINT 12

/* utility functions */
ssize_t _fd_getline_helper(char **, char **, size_t *);
void rm_newline_char(char **);
ssize_t fd_getline(char **, size_t *, int);
void free_vectr(char **);
void free_stack(stack_t *);
mf_type get_mfunc(char *);
size_t get_stacklen(stack_t *);
int is_int(char *, int *);
char **make_vectr(char *, char *);
int monty_exec_mgr(char **);
int monty_mgr(void);
char *str_dup(char *str);

/* op functions */
void monty_add(stack_t **, u_int);
void monty_div(stack_t **, u_int);
void monty_mod(stack_t **, u_int);
void monty_mul(stack_t **, u_int);
void monty_nop(stack_t **, u_int);
void monty_pall(stack_t **, u_int);
void monty_pchar(stack_t **, u_int);
void monty_pint(stack_t **, u_int);
void monty_pop(stack_t **, u_int);
void monty_pstr(stack_t **, u_int);
void monty_push(stack_t **, u_int);
void monty_rotl(stack_t **, u_int);
void monty_rotr(stack_t **, u_int);
void monty_sub(stack_t **, u_int);
void monty_swap(stack_t **, u_int);

#endif /* MONTY_H */
