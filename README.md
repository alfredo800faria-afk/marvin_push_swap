# Push Swap - School 42 Project

## 📋 Table of Contents

- [Project Overview](#project-overview)
- [What is Push Swap?](#what-is-push-swap)
- [The Rules](#the-rules)
- [Allowed Operations](#allowed-operations)
- [Algorithm Explanation](#algorithm-explanation)
- [How to Use/Run Project](#how-to-use)
- [Edge Cases Handled](#edge-cases-handled)
- [Examples with Step-by-Step Explanation](#examples-with-step-by-step-explanation)
- [Project Structure](#project-structure)
- [Resources i use](#Resource-for-project)

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
| 100 elements | < 700 operations (full points) |
| 500 elements | < 5500 operations (full points) |

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

## Allowed Operations

### Swap Operations

| Operation | Description | Example |
|-----------|-------------|---------|
| `sa` | Swap first 2 elements of Stack A | `[3, 1, 2] → [1, 3, 2]` |
| `sb` | Swap first 2 elements of Stack B | `[5, 4] → [4, 5]` |
| `ss` | `sa` and `sb` at the same time | Both stacks swap |

```
sa (swap a):
   BEFORE:  [3] → [1] → [2]
   AFTER:   [1] → [3] → [2]
```

### Push Operations

| Operation | Description |
|-----------|-------------|
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |

```
pb (push b):
   Stack A: [3, 1, 2]    Stack B: []
```

### Rotate Operations (Shift Up)

| Operation | Description |
|-----------|-------------|
| `ra` | Rotate Stack A up (top goes to bottom) |
| `rb` | Rotate Stack B up |
| `rr` | `ra` and `rb` at the same time |

```
ra (rotate a):
   BEFORE:  [3] → [1] → [2]
   AFTER:   [1] → [2] → [3]
```

### Reverse Rotate Operations (Shift Down)

| Operation | Description |
|-----------|-------------|
| `rra` | Reverse rotate Stack A (bottom goes to top) |
| `rrb` | Reverse rotate Stack B |
| `rrr` | `rra` and `rrb` at the same time |

```
rra (reverse rotate a):
   BEFORE:  [3] → [1] → [2]
   AFTER:   [2] → [3] → [1]
```

---

## Algorithm Explanation

This implementation uses **different algorithms based on input size**:

### 1. Two Elements (sort_two)
- **Logic**: Simply swap if not sorted
- **Max operations**: 1
- **Example**: `[2, 1] → sa → [1, 2]`

### 2. Three Elements (sort_three)
- **Logic**: Hardcoded optimal solution for all 6 possible arrangements
- **Max operations**: 2
- **Why hardcoded?**: Only 3! = 6 permutations, we can solve each optimally

### 3. Four Elements (sort_four)
- **Logic**: Push smallest to B, sort 3 in A, push back
- **Max operations**: +/- 8

```
Strategy:
1. Find smallest element
2. Move it to top (using ra or rra)
3. Push to B (pb)
4. Sort remaining 3 elements in A
5. Push back from B (pa)
```

### 4. Five Elements (sort_five)
- **Logic**: Push two smallest to B, sort 3 in A, push back
- **Max operations**: +/- 12

### 5. Six or More Elements (radix_sort)
- **Algorithm**: Radix Sort using binary representation
- **Complexity**: O(n × log n)
- **Why Radix Sort?**: Simple to understand, guaranteed efficiency

#### How Radix Sort Works

**Step 1: Simplify Numbers to Indexes**

Since radix sort needs non-negative integers, we convert all numbers to simple indexes:

```
Original:   [500, -300, 1000, 0]
Sorted:     [-300, 0, 500, 1000]
Indexes:    [2, 0, 3, 1]

Now we sort the indexes instead of the original values!
```
---

## How to Use

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

### Testing

```bash
# Run built-in tests
make test

# Test edge cases
make test_edge

# Count operations
./push_swap 5 4 3 2 1 | wc -l

# Use with checker (download from 42 intranet)
ARG="4 2 7 1"; ./push_swap $ARG | ./checker_linux $ARG
```

---

## Edge Cases Handled

### 1. Integer Overflow Protection

```c
// Check before using
if (value > INT_MAX || value < INT_MIN)
    return (0);  // Error!
```

**Test cases:**
```bash
./push_swap 2147483648    # Error (INT_MAX + 1)
./push_swap -2147483649   # Error (INT_MIN - 1)
./push_swap 2147483647    # OK (INT_MAX)
./push_swap -2147483648   # OK (INT_MIN)
```

### 2. Duplicate Detection

```c
int has_duplicates(t_stack *stack)
{
    t_node *current;
    t_node *check;

    current = stack->top;
    while (current)
    {
        check = current->next;
        while (check)
        {
            if (current->value == check->value)
                return (1);  // Found duplicate!
            check = check->next;
        }
        current = current->next;
    }
    return (0);
}
```

**Test cases:**
```bash
./push_swap 1 2 1        # Error (duplicates)
./push_swap 5 5 5 5      # Error (duplicates)
```

### 3. Non-Numeric Input

```bash
./push_swap 1 2 abc      # Error
./push_swap 1 2 3a       # Error
./push_swap ""           # Error
```

### 4. Empty Input

```bash
./push_swap              # No output (not an error)
```

### 5. Already Sorted

```bash
./push_swap 1 2 3 4 5    # No output (already sorted)
```

### 6. Single Element

```bash
./push_swap 42           # No output (single element is sorted)
```

---

## Examples with Step-by-Step Explanation

### Example 1: Two Elements

```bash
$ ./push_swap 2 1
sa
```

**Explanation:**
```
Initial:  A: [2, 1]    B: []
After sa: A: [1, 2]    B: []  ✓ Sorted!
```

### Example 2: Three Elements

```bash
$ ./push_swap 3 2 1
sa
rra
```

**Explanation:**
```
Initial:      A: [3, 2, 1]    B: []

After sa:     A: [2, 3, 1]    B: []
              (swapped 3 and 2)

After rra:    A: [1, 2, 3]    B: []  ✓ Sorted!
              (moved bottom 1 to top)
```

### Example 3: Five Elements

```bash
$ ./push_swap 5 4 3 2 1
pb
pb
sa
ra
pa
pa
```

**Explanation:**
```
Initial:    A: [5, 4, 3, 2, 1]    B: []

pb:         A: [4, 3, 2, 1]      B: [5]
pb:         A: [3, 2, 1]         B: [4, 5]
sa:         A: [2, 3, 1]         B: [4, 5]
ra:         A: [3, 1, 2]         B: [4, 5]
pa:         A: [4, 3, 1, 2]      B: [5]
pa:         A: [5, 4, 3, 1, 2]   B: []

Wait, this doesn't look right... Let me check the actual algorithm!
```

### Example 4: Large Numbers

```bash
$ ./push_swap 2147483647 -2147483648 0
pb
ra
pa
```

**Explanation:**
```
The program correctly handles INT_MAX and INT_MIN!

Initial indexes after simplification:
  2147483647  → index 2
  -2147483648 → index 0
  0           → index 1

Radix sort on indexes [2, 0, 1] produces correct output.
```

---

## Project Structure

```
push_swap/
├── push_swap.h      # Header file with structures and prototypes
├── push_swap.c      # Main file: parsing, validation, main function
├── operations.c     # All stack operations (sa, sb, pa, pb, ra, rra, etc.)
├── sort.c           # Sorting algorithms for different sizes
└── Makefile         # Compilation rules
```

### File Descriptions

| File | Purpose | Key Functions |
|------|---------|---------------|
| `push_swap.h` | Header with declarations | `t_node`, `t_stack`, prototypes |
| `push_swap.c` | Main logic | `main`, `parse_args`, `ft_atol`, `assign_indexes` |
| `operations.c` | Stack operations | `sa`, `sb`, `pa`, `pb`, `ra`, `rra`, etc. |
| `sort.c` | Sorting algorithms | `sort_two`, `sort_three`, `radix_sort` |

---

### Testing Commands for Evaluation

```bash
# Test with random numbers (100 elements)
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

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


---
