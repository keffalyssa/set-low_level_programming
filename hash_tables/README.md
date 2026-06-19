# Hash Tables - 0x1A

## Description

This project implements a **Hash Table** data structure in C. A hash table maps keys to values for efficient lookup using a hash function.

## Files

| File | Description |
|------|-------------|
| `hash_tables.h` | Header file with struct definitions and function prototypes |
| `0-hash_table_create.c` | Creates a hash table |

## Data Structures

```c
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
```

## Tasks

### 0. hash_table_create

Prototype: `hash_table_t *hash_table_create(unsigned long int size);`
- Returns a pointer to the new hash table
- Returns NULL if something goes wrong

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89
```

## Author

Teta - ALX Software Engineering Program
