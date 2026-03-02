This project has been created as part of the 42 curriculum by srusso-b

# Project Push Swap
---

## Project Overview

**Push Swap** is a sorting algorithm project at School 42. The goal is to sort a stack of integers using the **minimum number of operations**, using only a limited set of allowed moves and two stacks.

### The Challenge

You are given:
- **Stack A**: Contains random integers (can be positive, negative, or zero)
- **Stack B**: Empty at the start

You must sort Stack A in **ascending order** (smallest on top) using only the allowed operations.

### Performance Requirements

| Number of Elements | Maximum Operations Allowed |
|-------------------|---------------------------|
| 3 elements | ≤ 3 operations |
| 5 elements | ≤ 12 operations |
| 100 elements | < 700 operations |
| 500 elements | < 5500 operations |

---

## What is Push Swap?

### The Two Stacks

```
Stack A                    Stack B
┌─────┐                   ┌─────┐
│  3  │ ← TOP             │     │ ← TOP
├─────┤                   ├─────┤
│  1  │                   │     │
├─────┤                   ├─────┤
│  4  │                   │     │
├─────┤                   ├─────┤
│  2  │                   │     │
└─────┘                   └─────┘
```

### The Goal

Transform Stack A from unsorted to sorted (smallest at top):

```
BEFORE:                    AFTER:
Stack A                    Stack A
┌─────┐                   ┌─────┐
│  3  │                   │  1  │ ← Smallest
├─────┤                   ├─────┤
│  1  │        →          │  2  │
├─────┤                   ├─────┤
│  4  │                   │  3  │
├─────┤                   ├─────┤
│  2  │                   │  4  │ ← Largest
└─────┘                   └─────┘
```

---

## The Rules

### What You Can Do
1. Use only the **11 allowed operations**
2. Use **Stack B** as temporary storage
3. Print operations as you perform them

### What You Cannot Do
1. No other sorting operations allowed
2. Cannot directly access elements (only through operations)
3. Cannot use built-in sorting functions

### Input Validation
Your program must detect and report errors for:
- Non-integer values
- Duplicate numbers
- Numbers outside INT range (-2147483648 to 2147483647)

---
### Operations Available

The program can only use these 11 operations:

**Swap Operations:**
- `sa`: Swap first 2 elements of stack A
- `sb`: Swap first 2 elements of stack B
- `ss`: sa and sb simultaneously

**Push Operations:**
- `pa`: Push first element of B to A
- `pb`: Push first element of A to B

**Rotate Operations:**
- `ra`: Rotate stack A up (first → last)
- `rb`: Rotate stack B up
- `rr`: ra and rb simultaneously

**Reverse Rotate Operations:**
- `rra`: Rotate stack A down (last → first)
- `rrb`: Rotate stack B down
- `rrr`: rra and rrb simultaneously
---

## Strategy:
1. Find smallest element
2. Move it to top (using ra or rra)
3. Push to B (pb)
4. Sort remaining 3 elements in A
5. Push back from B (pa)

---

### Compilation

```bash
# Compile the project
make

# Clean object files
make clean

# Remove everything
make fclean

# Rebuild
make re
```
---

### Running the Program

```bash
# Basic usage
./push_swap 4 2 7 1

# With quotes (single argument)
./push_swap "4 2 7 1"

# With negative numbers
./push_swap -5 3 -1 0 2

# With INT_MAX and INT_MIN
./push_swap 2147483647 -2147483648 0

# Multiple formats combined
./push_swap 1 2 "3 4" 5
```
---

### Testing

```bash
# Run built-in tests
make test

# Test edge cases
make test_edge

# Count operations
./push_swap 5 4 3 2 1 | wc -l

# Use with checker
ARG="4 2 7 1"; ./push_swap $ARG | ./checker_linux $ARG
```

---

## Project Structure

```
project-root/
├── Makefile                      # Build instructions for the project
├── push_swap.c                  # Main entry point for the Push Swap program
├── push_swap.h                  # Header file containing function declarations and macros
├── sort.c                       # Implementation of sorting algorithms
├── libft/                       # Custom library for utility functions
│   ├── ft_atoi.c                # Converts a string to an integer
│   ├── ft_isdigit.c             # Checks if a character is a digit
│   ├── ft_lstadd_back.c         # Adds a node to the end of a linked list
│   ├── ft_lstnew.c              # Creates a new linked list node
│   └── func_ptr.c               # Contains function pointers for various operations
├── moves/                       # Contains functions related to stack operations
│   ├── push.c                   # Pushes an element onto the stack
│   ├── revrotate.c              # Rotates the stack in the reverse direction
│   ├── rotate.c                 # Rotates the stack in the forward direction
│   └── swap.c                   # Swaps the top two elements of the stack
└── parse/                       # Functions for parsing input and handling stack data
    ├── check_input.c            # Validates user input for correctness
    ├── fill_stack.c             # Fills a stack with input values
    ├── find_util.c              # Utility functions for finding elements in the stack
    ├── get_ops.c                # Retrieves operations based on input
    └── get_util.c               # Other utility functions for the parsing process
```
---

### Testing Commands for Evaluation

```bash
# Test with random numbers (100 elements)
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ); ./push_swap $ARG | wc -l

# Test with random numbers (500 elements)
ARG=$(seq -1000 1000 | shuf -n 500); ./push_swap $ARG | wc -l

# Verify correctness with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Test edge cases
./push_swap 2147483647 -2147483648           # INT_MAX/MIN
./push_swap 1 1 2                            # Duplicates
./push_swap 999999999999999999999999999      # Overflow
```

---

## Resource for project

[Dynamicdispatch project push_swap](https://dynamicdispat.ch/posts/2024/01/push-swap/)

[42 Tokyo Project Push Swap](https://zenn.dev/uta_san1012/articles/bfa9cabfeadc51)

[Yigit Ogun Push Swap](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

[To0nsa Push Swap Gitbook](https://to0nsa.github.io/push_swap/)

---
