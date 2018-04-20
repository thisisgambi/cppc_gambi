# C++ Practical Course - s18

During the last part of my Computer Science studies at the 
Ludwig-Maximilians-University (short LMU) in Munich I am one of the lucky ones 
allowed to participate in a practical course about advanced 
software development (with examples done in C++).

This repo will be continued throughout the course and will be my very own spot
for notes. I am pretty sure that I have to get over this again and again
while I am learning the concepts and prinicples of modern software 
development.

**WORK IN PROGRESS**

## Session 1:

- Basics
- The C language

## Session 2:

What happens if the compiler sees the following expression ?:

```lang=c
const int x = 123;
const int y = 345;

int var = x + y;
```



Abstraction always causes overhead:
- Yes! But when?
  - Runtime vs compile time

const int * cip;
int * const ipc;


### Read-only pointer to int

const int * const

### Remember:

- read from right to left for manual, mental type deduction
- Rule of Three
- operators are the same as methods
  - function: can be called several times and it will not change any of the parameters
  - method: may change the parameters (??)
- think in concepts; Classes are user-defined types that hold against certain concepts in the form of a program;

