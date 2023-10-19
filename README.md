# 0x19. C - Stacks, Queues - LIFO, FIFO

## General
-	What do LIFO and FIFO mean
-	What is a stack, and when to use it
-	What is a queue, and when to use it
-	What are the common implementations of stacks and queues
-	What are the most common use cases of stacks and queues
-	What is the proper way to use global variables
-	Allowed editors: vi, vim, emacs
-	All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
-	All your files should end with a new line
-	A README.md file, at the root of the folder of the project is mandatory
-	Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
-	You allowed to use a maximum of one global variable
-	No more than 5 functions per file
-	You are allowed to use the C standard library
-	The prototypes of all your functions should be included in your header file called monty.h
-	Don’t forget to push your header file
-	All your header files should be include guarded
-	You are expected to do the tasks in the order shown in the project

## Compilation & Output
Your code will be compiled this way:
<code>$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty</code>
-	Any output must be printed on stdout
-	Any error message must be printed on stderr
-	Here is a link to a GitHub repository (https://github.com/ku1ik/stderred) that could help you making sure your errors are printed on stderr

# The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

-	Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument
-	Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account

### The monty program

-	Usage: monty file
	-	where file is the path to the file containing Monty byte code
-	If the user does not give any file or more than one argument to your program, print the error message USAGE: monty file, followed by a new line, and exit with the status EXIT_FAILURE
-	If, for any reason, it’s not possible to open the file, print the error message Error: Can't open file <file>, followed by a new line, and exit with the status EXIT_FAILURE
	-	where <file> is the name of the file
-	If the file contains an invalid instruction, print the error message L<line_number>: unknown instruction <opcode>, followed by a new line, and exit with the status EXIT_FAILURE
	-	where is the line number where the instruction appears.
	-	Line numbers always start at 1
-	The monty program runs the bytecodes line by line and stop if either:
	-	it executed properly every line of the file
	-	it finds an error in the file
	-	an error occured
-	If you can’t malloc anymore, print the error message Error: malloc failed, followed by a new line, and exit with status EXIT_FAILURE.
-	You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

## Features
### Opcodes
The `monty` executes the following opcodes:

| Opcode             	| 	Description                                                                             		|
| -------------------- 	| --------------------------------------------------------------------------------------------------------------|
| `push` 		| 	Pushes an element to the stack 										|
| `pall` 		| 	Prints all the values on the stack									|
| `pint` 		| 	Prints the value at the top of the stack 								|
| `pop` 		| 	Removes the top element of the stack 									|
| `swap` 		| 	Swaps the top two elements of the stack 								|
| `nop` 		| 	Implements nop code 											|
| `add` 		| 	Adds the top two elements of the stack 									|
| `sub` 		| 	Subtracts the top element of the stack from the second top element of the stack 			|
| `mul` 		| 	Multiplies the second top element of the stack with the top element of the stack 			|
| `div` 		| 	Divides the second top element of the stack by the top element of the stack 				|
| `mod` 		| 	Computes the rest of the division of the second top element of the stack by the top element of the stack|
| `pchar` 		| 	Prints the char at the top of the stack 								|
| `pstr` 		| 	Prints the string starting at the top of the stack 							|
| `rotl` 		| 	Rotates the stack to the top 										|
| `rotr` 		| 	Rotates the stack to the bottom 									|

# Tasks
## Task 0. push, pall

mandatory

Implement the push and pall opcodes.

<strong>The push opcode</strong>

The opcode push pushes an element to the stack.

-	Usage: push \<int>
	-	where \<int> is an integer
-	if \<int> is not an integer or if there is no argument given to push, print the error message <code>L\<line_number></code>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
	-	where is the line number in the file
-	You won’t have to deal with overflows. Use the atoi function

<strong>The pall opcode</strong>

The opcode pall prints all the values on the stack, starting from the top of the stack.

-	Usage pall
-	Format: see example
-	If the stack is empty, don’t print anything

Repo:

		GitHub repository: monty


## Task 1. pint

mandatory

Implement the pint opcode.

<strong>The pint opcode</strong>

The opcode pint prints the value at the top of the stack, followed by a new line.

-	Usage: pint
-	If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

Repo:

		GitHub repository: monty


## 2. pop

mandatory

Implement the pop opcode.

<strong>The pop opcode</strong>

The opcode pop removes the top element of the stack.

-	Usage: pop
-	If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

Repo:

		GitHub repository: monty


## Task 3. swap

mandatory

Implement the swap opcode.

<strong>The swap opcode</strong>

The opcode swap swaps the top two elements of the stack.

-	Usage: swap
-	If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

Repo:

		GitHub repository: monty


## Task 4. add

mandatory

Implement the add opcode.

<strong>The add opcode</strong>

The opcode add adds the top two elements of the stack.

-	Usage: add
-	If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
-	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	-	The top element of the stack contains the result
	-	The stack is one element shorter

Repo:

		GitHub repository: monty


## Task 5. nop

mandatory

Implement the nop opcode.

<strong>The nop opcode</strong>

The opcode nop doesn’t do anything.

-	Usage: nop

Repo:

			GitHub repository: monty


## Task 6. sub
#advanced

Implement the sub opcode.

<strong>The sub opcode</strong>

The opcode sub subtracts the top element of the stack from the second top element of the stack.

-	Usage: sub
-	If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
-	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	-	The top element of the stack contains the result
	-	The stack is one element shorter

Repo:

		GitHub repository: monty


## Task 7. div
#advanced

Implement the div opcode.

<strong>The div opcode</strong>

The opcode div divides the second top element of the stack by the top element of the stack.

-	Usage: div
-	If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
-	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	-	The top element of the stack contains the result
	-	The stack is one element shorter
-	If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

Repo:

		GitHub repository: monty


## Task 8. mul
#advanced

Implement the mul opcode.

<strong>The mul opcode</strong>

The opcode mul multiplies the second top element of the stack with the top element of the stack.

-	Usage: mul
-	If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
-	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	-	The top element of the stack contains the result
	-	The stack is one element shorter

Repo:

		GitHub repository: monty

## Task 9. mod
#advanced

Implement the mod opcode.

<strong>The mod opcode</strong>

The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

-	Usage: mod
-	If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
-	The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	-	The top element of the stack contains the result
	-	The stack is one element shorter
-	If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

Repo:

		GitHub repository: monty


## Task 10. comments
#advanced

Every good language comes with the capability of commenting. When the first non-space character of a line is #, treat this line as a comment (don’t do anything).

Repo:

		GitHub repository: monty

## Task 11. pchar
#advanced

Implement the pchar opcode.

<strong>The pchar opcode</strong>

The opcode pchar prints the char at the top of the stack, followed by a new line.

-	Usage: pchar
-	The integer stored at the top of the stack is treated as the ascii value of the character to be printed
-	If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
-	If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

Repo:

		GitHub repository: monty


##Task 12. pstr
#advanced

Implement the pstr opcode.

<strong>The pstr opcode</strong>

The opcode pstr prints the string starting at the top of the stack, followed by a new line.

-	Usage: pstr
-	The integer stored in each element of the stack is treated as the ascii value of the character to be printed
-	The string stops when either:
	-	the stack is over
	-	the value of the element is 0
	-	the value of the element is not in the ascii table
-	If the stack is empty, print only a new line

Repo:

		GitHub repository: monty


## Task 13. rotl
#advanced

Implement the rotl opcode.

<strong>The rotl opcode</strong>

The opcode rotl rotates the stack to the top.

-	Usage: rotl
-	The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
-	rotl never fails

Repo:

		GitHub repository: monty


## Task 14. rotr
#advanced

Implement the rotr opcode.

<strong>The rotr opcode</strong>

The opcode rotr rotates the stack to the bottom.

-	Usage: rotr
-	The last element of the stack becomes the top element of the stack
-	rotr never fails

Repo:

		GitHub repository: monty


## Task 15. stack, queue
#advanced

Implement the stack and queue opcodes.

<strong>The stack opcode</strong>

The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.

-	Usage: stack

<strong>The queue opcode</strong>

The opcode queue sets the format of the data to a queue (FIFO).

-	Usage: queue

When switching mode:

-	The top of the stack becomes the front of the queue
-	The front of the queue becomes the top of the stack
 
Repo:

		GitHub repository: monty


## Task 16. Brainf*ck
#advanced

Write a Brainf*ck script that prints School, followed by a new line.

-	All your Brainf*ck files should be stored inside the bf sub directory
-	You can install the bf interpreter to test your code: sudo apt-get install bf
-	Read: Brainf*ck (https://en.wikipedia.org/wiki/Brainfuck)

Repo:

		GitHub repository: monty
		Directory: bf
		File: 1000-school.bf


## Task 17. Add two digits
#advanced

Add two digits given by the user.

-	Read the two digits from stdin, add them, and print the result
-	The total of the two digits with be one digit-long (<10)

Repo:

		GitHub repository: monty
		Directory: bf
		File: 1001-add.bf


##Task 18. Multiplication
#advanced

Multiply two digits given by the user.

-	Read the two digits from stdin, multiply them, and print the result
-	The result of the multiplication will be one digit-long (<10)

Repo:

		GitHub repository: monty
		Directory: bf
		File: 1002-mul.bf


## Task 19. Multiplication level up
#advanced

Multiply two digits given by the user.

-	Read the two digits from stdin, multiply them, and print the result, followed by a new line

Repo:

		GitHub repository: monty
		Directory: bf
		File: 1003-mul.bf


