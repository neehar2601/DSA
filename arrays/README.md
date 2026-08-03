# Arrays

> **Phase:** Phase 1 — Foundations  
> **Status:** 🟡 In Progress  
> **Problems Solved:** 1 Easy · 0 Medium · 0 Hard

---

## Introduction

An **array** is the most fundamental data structure in computer science — a contiguous block of memory that stores elements of the same type, each accessible in O(1) time via an index. Nearly every algorithm problem either uses arrays directly or maps to an array-like structure under the hood.

Mastering arrays means mastering:

- Direct index access and traversal
- In-place manipulation
- The tradeoff between space (auxiliary arrays) and time (single-pass techniques)
- Building blocks for more complex structures: heaps, hash tables, segment trees

---

## Theory

### Memory Layout

Arrays store elements **contiguously** in memory. If the base address is `addr` and each element occupies `size` bytes, element `i` lives at:

```
address(i) = base_addr + i × element_size
```

This is why random access is always **O(1)** — the CPU computes the address directly.

```
Index:    0       1       2       3       4
        ┌───────┬───────┬───────┬───────┬───────┐
Value:  │  10   │  20   │  30   │  40   │  50   │
        └───────┴───────┴───────┴───────┴───────┘
Addr:  1000    1004    1008    1012    1016      (assuming 4 bytes/int)
```

### Static vs Dynamic Arrays

| Property | Static (C array) | Dynamic (Python list) |
|----------|-----------------|----------------------|
| Size | Fixed at creation | Grows automatically |
| Access | O(1) | O(1) |
| Append | N/A | Amortized O(1) |
| Insert at index | O(n) shift | O(n) shift |
| Memory | Minimal overhead | Overallocates (1.125×) |

### Zero-based Indexing

All major languages (C, Python, Java, C++) use **0-based indexing**. The last valid index is always `len - 1`. Off-by-one errors at boundaries are the single most common array bug.

---

## Time Complexity

| Operation | Best | Average | Worst | Notes |
|-----------|------|---------|-------|-------|
| Access by index | O(1) | O(1) | O(1) | Direct address computation |
| Search (unsorted) | O(1) | O(n) | O(n) | Linear scan |
| Search (sorted) | O(1) | O(log n) | O(log n) | Binary search |
| Insert at end | O(1) | O(1) | O(n) | Resize in dynamic arrays |
| Insert at index | O(1) | O(n) | O(n) | Shifts n elements |
| Delete at index | O(1) | O(n) | O(n) | Shifts n elements |
| Traverse | O(n) | O(n) | O(n) | Must visit every element |

## Space Complexity

| Scenario | Complexity | Notes |
|----------|------------|-------|
| Store n elements | O(n) | The array itself |
| In-place algorithm | O(1) | No extra space used |
| Prefix sum array | O(n) | Mirror of original |
| Hash map from array | O(n) | Space-time tradeoff |

---

## Common Operations

### Traversal

```python
# Forward
for i in range(len(arr)):
    print(arr[i])

# Backward
for i in range(len(arr) - 1, -1, -1):
    print(arr[i])

# With index and value (prefer this)
for i, val in enumerate(arr):
    print(i, val)
```

```c
int n = sizeof(arr) / sizeof(arr[0]);
for (int i = 0; i < n; i++) {
    printf("%d\n", arr[i]);
}
```

### Two-pointer swap (in-place reverse)

```python
left, right = 0, len(arr) - 1
while left < right:
    arr[left], arr[right] = arr[right], arr[left]
    left += 1
    right -= 1
```

### Prefix sum

```python
prefix = [0] * (len(arr) + 1)
for i, val in enumerate(arr):
    prefix[i + 1] = prefix[i] + val

# Range sum [l, r] in O(1)
range_sum = prefix[r + 1] - prefix[l]
```

---

## Common Patterns

| Pattern | Core Idea | When to Use |
|---------|-----------|-------------|
| **Two Pointers** | One pointer from each end, converge | Sorted arrays, pair problems |
| **Sliding Window** | Fixed or variable window over array | Subarray sum/max/min problems |
| **Prefix Sum** | Precompute cumulative sums | Repeated range queries |
| **Hash Map** | Value → index lookup | Complement search (Two Sum) |
| **Sorting** | Sort then apply simpler logic | Reduces search to binary |
| **Kadane's Algorithm** | Track running max subarray | Maximum subarray sum |
| **Binary Search** | Halve search space each step | Sorted arrays, answer-space search |
| **Monotonic Stack** | Maintain sorted invariant | Next greater/smaller element |

---

## Common Mistakes

1. **Off-by-one at boundaries** — always double check `< n` vs `<= n` and `i - 1` vs `i`.
2. **Modifying an array while iterating** — create a copy or iterate backwards.
3. **Assuming the array is sorted when it's not** — read the constraints.
4. **Integer overflow in index math** — `mid = left + (right - left) // 2` not `(left + right) // 2`.
5. **Forgetting that Python slicing creates copies** — `arr[:]` costs O(n) space.
6. **Not handling empty array edge case** — always check `if not arr` first.
7. **Using O(n) `in` check on a list instead of a set** — linear scan vs O(1).

---

## Interview Questions

1. **What is the time complexity of inserting at the beginning of an array vs a linked list?** Arrays O(n), linked lists O(1).
2. **When would you choose a dynamic array over a linked list?** Arrays have better cache locality and O(1) random access; use them when indexing and traversal dominate over insertions/deletions.
3. **How does a hash map turn Two Sum from O(n²) to O(n)?** Store complement → index mapping; look up in O(1) instead of scanning.
4. **What does "in-place" mean and why does it matter?** Algorithm mutates input array without proportional extra space; critical for O(1) space solutions.
5. **Explain Kadane's Algorithm.** Track current subarray sum; reset to 0 (or current element) when it goes negative; global max is the answer.

---

## Problems

| # | Problem | Difficulty | Key Pattern | Python | C |
|---|---------|------------|-------------|--------|---|
| [LC0001](easy/LC0001-two-sum/README.md) | Two Sum | 🟢 Easy | Hash Map | [solution.py](easy/LC0001-two-sum/python/solution.py) | [solution.c](easy/LC0001-two-sum/c/solution.c) |

---

## References

- [Python List Internals — CPython source](https://github.com/python/cpython/blob/main/Objects/listobject.c)
- [Arrays — GeeksforGeeks](https://www.geeksforgeeks.org/array-data-structure/)
- [VisuAlgo — Array Sorting](https://visualgo.net/en/sorting)
- [NeetCode Arrays playlist](https://neetcode.io/roadmap)
