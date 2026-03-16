#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: the string to print
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
}
```

---

**File 2: `README.md`**
```
# 0x08. C - Recursion

## Description
This project covers the concept of recursion in C programming.
Recursion is a technique where a function calls itself to solve
smaller instances of a problem until it reaches a base case.

## Learning Objectives
- What is recursion
- How to implement recursion
- When to implement recursion
- When not to implement recursion

## Requirements
- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using gcc
- Flags: -Wall -Werror -Wextra -pedantic -std=gnu89
- No global variables allowed
- No more than 5 functions per file
- No static variables allowed

## Files
- 0-puts_recursion.c - Prints a string followed by a new line

## Repository
- GitHub repository: set-low_level_programming
- Directory: 0x08-recursion
