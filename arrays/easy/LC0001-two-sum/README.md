# LC0001 · Two Sum

> **Platform:** LeetCode  
> **Problem ID:** [LC #1](https://leetcode.com/problems/two-sum/)  
> **Difficulty:** 🟢 Easy  
> **Topic:** Arrays · Hash Map  

---

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the **indices** of the two numbers that add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice. You can return the answer in any order.

---

## Examples

**Example 1:**

```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

**Example 2:**

```
Input:  nums = [3, 2, 4], target = 6
Output: [1, 2]
Explanation: nums[1] + nums[2] = 2 + 4 = 6
```

**Example 3:**

```
Input:  nums = [3, 3], target = 6
Output: [0, 1]
```

---

## Constraints

- `2 <= nums.length <= 10⁴`
- `-10⁹ <= nums[i] <= 10⁹`
- `-10⁹ <= target <= 10⁹`
- Exactly one valid answer exists.

---

## Intuition

For each number `x` in the array, we need to find `target - x`. The brute-force approach checks every pair (O(n²)). The key insight: we can answer "have we seen `target - x` before?" in **O(1)** using a hash map. We build the map as we walk — when we find a complement already stored, we immediately return both indices.

---

## Brute Force Approach

**Idea:** For every pair `(i, j)` with `i < j`, check if `nums[i] + nums[j] == target`.

**Steps:**

1. Outer loop: for each index `i` from 0 to n-1.
2. Inner loop: for each index `j` from `i+1` to n-1.
3. If `nums[i] + nums[j] == target`, return `[i, j]`.

**Time:** O(n²) — checks every pair  
**Space:** O(1) — no extra storage

---

## Optimal Approach

**Idea:** Walk the array once; maintain a hash map from `value → index`. For each element, check if its complement is already in the map.

**Steps:**

1. Initialize an empty hash map `seen = {}`.
2. For each index `i` and value `num` in `nums`:
   - Compute `complement = target - num`.
   - If `complement` is in `seen`, return `[seen[complement], i]`.
   - Otherwise, store `seen[num] = i`.
3. Return `[]` (unreachable given the problem guarantees).

**Time:** O(n) — single pass over the array  
**Space:** O(n) — hash map holds up to n entries

---

## Python Solution

```python
from typing import List

def two_sum(nums: List[int], target: int) -> List[int]:
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []
```

See the full file: [python/solution.py](python/solution.py)

---

## C Solution

```c
#include <stdlib.h>
#include <string.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /* Hash table: open addressing with linear probing */
    int cap = numsSize * 2;
    int *keys   = malloc(cap * sizeof(int));
    int *values = malloc(cap * sizeof(int));
    memset(keys,   0, cap * sizeof(int));
    memset(values, -1, cap * sizeof(int));

    int *result = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        /* Look up complement */
        int slot = ((complement % cap) + cap) % cap;
        while (values[slot] != -1 && keys[slot] != complement)
            slot = (slot + 1) % cap;
        if (values[slot] != -1 && keys[slot] == complement) {
            result[0] = values[slot];
            result[1] = i;
            free(keys); free(values);
            return result;
        }
        /* Store current number */
        slot = ((nums[i] % cap) + cap) % cap;
        while (values[slot] != -1 && keys[slot] != nums[i])
            slot = (slot + 1) % cap;
        keys[slot]   = nums[i];
        values[slot] = i;
    }
    free(keys); free(values);
    return result;
}
```

See the full file: [c/solution.c](c/solution.c)

---

## Dry Run

**Input:** `nums = [2, 7, 11, 15]`, `target = 9`

| Step | i | num | complement | seen (before check) | Action |
|------|---|-----|------------|---------------------|--------|
| 1 | 0 | 2 | 7 | `{}` | 7 not found → store `{2: 0}` |
| 2 | 1 | 7 | 2 | `{2: 0}` | 2 **found** at index 0 → return `[0, 1]` ✓ |

---

## Edge Cases

| Input | Expected | Why |
|-------|---------|-----|
| `[3, 3], target=6` | `[0, 1]` | Same value at different indices — map stores first occurrence, second occurrence finds it |
| `[-3, 4, 3, 90], target=0` | `[0, 2]` | Negative numbers; complement of `-3` is `3` |
| `[1, 2, 3], target=100` | `[]` | No valid pair (not possible per constraints, but code handles it) |

---

## Related Problems

| Problem | Platform | Similarity |
|---------|----------|------------|
| [3Sum](https://leetcode.com/problems/3sum/) | LC #15 | Extend Two Sum to three elements |
| [4Sum](https://leetcode.com/problems/4sum/) | LC #18 | Extend further |
| [Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | LC #167 | Sorted variant → two pointers |
| [Two Sum III](https://leetcode.com/problems/two-sum-iii-data-structure-design/) | LC #170 | Design a data structure |
