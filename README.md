# Project Push Swap
---

> **42 School Project** — Sort a stack of integers using the minimum number of operations.

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="C">
  <img src="https://img.shields.io/badge/42_Project-Push_Swap-green.svg" alt="42 Project">
  <img src="https://img.shields.io/badge/Performance-%3C5500_moves_for_500_nums-orange.svg" alt="Performance">
  <img src="https://img.shields.io/badge/Norminette-Compliant-brightgreen.svg" alt="Norminette">
</p>

---

## 🎯 Project Overview

**Push Swap** is a classic algorithmic challenge from the 42 School curriculum. The objective is to sort a stack of integers in ascending order (smallest on top) using only a restricted set of stack operations, while minimizing the total number of moves.

### The Challenge

You are given:
- **Stack A**: Contains random integers (positive, negative, or zero)
- **Stack B**: Empty at the start

Your program must output a sequence of operations that sorts Stack A using the **fewest moves possible**.

---

## ⚙️ Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first 2 elements of stack A |
| `sb` | Swap first 2 elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push top element from B to A |
| `pb` | Push top element from A to B |
| `ra` | Rotate stack A (shift up; first becomes last) |
| `rb` | Rotate stack B |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (shift down; last becomes first) |
| `rrb` | Reverse rotate stack B |
| `rrr` | Perform `rra` and `rrb` simultaneously |

---

## 🛠️ Compilation & Usage

### Build the project

```bash
# Compile the project
make

# Clean object files
make clean

# Remove all built files
make fclean

# Rebuild from scratch
make re
```

### Run the program

```bash
# Basic usage with numbers as arguments
./push_swap 3 1 2 4

# With negative numbers and duplicates check
./push_swap -5 10 0 3 -1

# Generate random test with Python helper
python3 -c "import random; l = list(range(-250, 250)); random.shuffle(l); print(' '.join(map(str, l)))" | xargs ./push_swap
```

### Verify output with checker

```bash
# Or with Linux checker
./push_swap 4 2 1 3 | ./checker_linux 4 2 1 3
```

---

## 🚀 Performance Goals

This implementation is optimized to meet 42's scoring criteria:

| Input Size | Target Moves | Grade Threshold |
|------------|-------------|-----------------|
| 3 numbers | ≤ 3 moves | ✅ |
| 5 numbers | ≤ 12 moves | ✅ |
| 100 numbers | ≤ 700 moves | ✅ |
| **500 numbers** | **< 5500 moves** | 🎯 **Rank 2 Target** |

> 💡 The algorithm uses chunk-based sorting with median partitioning and bit-optimized comparisons to achieve efficient sorting within move constraints.

---

## 📁 Project Structure

```
marvin_push_swap/
├── Makefile              # Build configuration with clean/fclean/re targets
├── push_swap.c           # Main entry point: arg parsing, validation, execution
├── push_swap.h           # Header: function declarations, macros, constants
├── parse_args.c          # Input validation and argument parsing logic
├── utils_parse.c         # Helper functions for parsing utilities
├── sort.c                # Core sorting algorithm implementation
├── utils_sort.c          # Sorting helpers: median, chunking, index mapping
├── swap_op.c             # sa, sb, ss operation implementations
├── push.c                # pa, pb push operations
├── rotate.c              # ra, rb rotation operations
├── rev_rotate.c          # rra, rrb reverse rotation operations
├── utils.c               # General utilities: stack management, printing
└── libft/                # (Optional) Custom utility library if used
    ├── ft_atoi.c
    ├── ft_isdigit.c
    └── ...
```

---

## 💡 Implementation Details

### Sorting Strategy
1. **Preprocessing**: Validate input, handle duplicates, map values to indexed ranks
2. **Small stacks** (≤3 elements): Direct hardcoded optimal sequences
3. **Medium stacks** (4-100): Insertion-sort inspired with rotation optimization
4. **Large stacks** (100-500):
   - Divide into chunks based on value ranges
   - Push elements to Stack B in strategic order
   - Reinsert into Stack A at correct positions using minimal rotations
   - Use combined operations (`ss`, `rr`, `rrr`) to reduce move count

### Optimization Techniques
- ✅ Bitwise operations for fast comparisons and flag handling
- ✅ Ternary operators for concise conditional logic
- ✅ Static arrays instead of dynamic allocation (no `malloc`)
- ✅ Precomputed median/index mappings to avoid repeated calculations
- ✅ Combined operation detection to output `ss`/`rr`/`rrr` when possible

---

## 🧪 Testing

### Manual Tests
```bash
# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1

# Random small set
./push_swap 42 -7 0 15 99

# Edge cases
./push_swap 0          # Single element
./push_swap 1 1        # Duplicate handling (should error)
./push_swap "abc"      # Invalid input (should error)
```

### Automated Performance Check
```bash
# Test move count for 500 random numbers
python3 -c "
import random, subprocess
nums = list(range(-250, 250))
random.shuffle(nums)
result = subprocess.run(['./push_swap'] + list(map(str, nums)),
                       capture_output=True, text=True)
moves = result.stdout.count('\n')
print(f'Moves for 500 numbers: {moves}')
print('✅ PASS' if moves < 5500 else '❌ FAIL')
"
```
---

## 📐 Code Style & Constraints

This project adheres to 42's strict coding standards:

- ✅ **Norminette compliant**: Follows 42's C style guide
- ✅ **No malloc**: Uses static arrays and stack-based allocation where possible
- ✅ **Modular design**: One function = one responsibility
- ✅ **Detailed comments**: Line-by-line explanations for complex logic
- ✅ **Minimal dependencies**: Pure C, standard library only
- ✅ **Error handling**: Graceful exit on invalid input with clear messages

> 📝 All functions include header comments describing purpose, parameters, and return values.

---

## 📜 License

This project is part of the 42 School curriculum and is intended for educational purposes.
Please respect academic integrity guidelines — use this repository for learning, not for direct submission.

> ⚠️ **Disclaimer**: Copying this code for evaluation may result in academic penalties at 42. Understand the algorithm, then implement your own version.

---

<p align="center">
  <strong>Happy Sorting! 🎲➡️📈</strong><br>
  <em>Optimize. Iterate. Dominate the stack.</em>
</p>
