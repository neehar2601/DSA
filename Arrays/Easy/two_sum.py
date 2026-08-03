"""
Problem: Two Sum
Platform: LeetCode #1
Difficulty: Easy
Link: https://leetcode.com/problems/two-sum/

Approach:
Walk the array once, keeping a hash map of value -> index for numbers
already seen. For each new number, check whether its complement
(target - number) is already in the map — if so, we've found the pair.
This trades O(n) extra space for a single O(n) pass instead of the
O(n^2) brute-force check of every pair.

Time Complexity:  O(n) — one pass over the array
Space Complexity: O(n) — hash map holds up to n entries
"""

from typing import List


def two_sum(nums: List[int], target: int) -> List[int]:
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []


if __name__ == "__main__":
    print(two_sum([2, 7, 11, 15], 9))  # [0, 1]
