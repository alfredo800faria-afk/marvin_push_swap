#!/usr/bin/env python
# Test move count for 500 random numbers
import random, subprocess
nums = list(range(-250, 250))
random.shuffle(nums)
result = subprocess.run(['./push_swap'] + list(map(str, nums)),
                       capture_output=True, text=True)
moves = result.stdout.count('\n')
print(f'Moves for 500 numbers: {moves}')
print('✅ PASS' if moves < 5500 else '❌ FAIL')
