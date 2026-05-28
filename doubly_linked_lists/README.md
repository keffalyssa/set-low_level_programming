# Doubly Linked Lists

## Description

This project covers the implementation of **doubly linked lists** in C. A doubly linked list is a data structure where each node contains a data field and two pointers — one pointing to the next node and one pointing to the previous node, allowing traversal in both directions.

## Data Structure

```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer stored in the node
 * @prev: pointer to the previous element of the list
 * @next: pointer to the next element of the list
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
```

## Files

| File | Description |
|------|-------------|
| `lists.h` | Header file with struct definition and function prototypes |
| `0-print_dlistint.c` | Prints all elements of a `dlistint_t` list |

## Functions

### `0-print_dlistint.c`
```c
size_t print_dlistint(const dlistint_t *h);
```
- Prints every node's integer value, one per line
- Returns the total number of nodes in the list

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-print_dlistint.c -o a
```

## Example Usage

```bash
$ ./a
9
8
-> 2 elements
```

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- Compiled on Ubuntu 20.04 LTS using `gcc` with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`
- All files end with a new line
- No more than 5 functions per file
- Only allowed to use `printf` and `malloc`/`free` from the C standard library
- Prototypes of all functions included in `lists.h`

## Repository

- **GitHub repository:** `set-low_level_programming`
- **Directory:** `doubly_linked_lists`
