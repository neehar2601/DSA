/*
 * Problem : Two Sum
 * Platform : LeetCode #1
 * Difficulty: Easy
 * Link     : https://leetcode.com/problems/two-sum/
 *
 * Approach:
 * Walk the array once using open-addressing hash table (linear probing).
 * For each element, check if its complement (target - nums[i]) is already
 * stored. If yes, return both indices. Otherwise, insert the current element.
 * Table capacity is 2× the input size to keep load factor ≤ 0.5.
 *
 * Time Complexity : O(n)  — single pass; each hash lookup/insert is O(1)
 * Space Complexity: O(n)  — hash table with 2n slots
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * twoSum — LeetCode-compatible signature.
 * Caller must free() the returned array.
 * *returnSize is set to 2 on success, 0 if no pair is found.
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int cap = numsSize * 2;

    /* Parallel arrays: keys store values, vals store indices (-1 = empty) */
    int *keys = malloc(cap * sizeof(int));
    int *vals = malloc(cap * sizeof(int));
    memset(vals, -1, cap * sizeof(int));  /* -1 marks empty slots */

    int *result = malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        /* ---- Look up complement ---- */
        int slot = ((complement % cap) + cap) % cap;  /* non-negative mod */
        while (vals[slot] != -1 && keys[slot] != complement)
            slot = (slot + 1) % cap;

        if (vals[slot] != -1) {  /* complement found */
            result[0] = vals[slot];
            result[1] = i;
            *returnSize = 2;
            free(keys);
            free(vals);
            return result;
        }

        /* ---- Store current number ---- */
        slot = ((nums[i] % cap) + cap) % cap;
        while (vals[slot] != -1 && keys[slot] != nums[i])
            slot = (slot + 1) % cap;
        keys[slot] = nums[i];
        vals[slot] = i;
    }

    /* No solution (unreachable per problem constraints) */
    free(keys);
    free(vals);
    return result;
}

int main(void) {
    /* Smoke tests */
    int returnSize;
    int nums1[] = {2, 7, 11, 15};
    int *r1 = twoSum(nums1, 4, 9, &returnSize);
    printf("[%d, %d]\n", r1[0], r1[1]);  /* Expected: [0, 1] */
    free(r1);

    int nums2[] = {3, 2, 4};
    int *r2 = twoSum(nums2, 3, 6, &returnSize);
    printf("[%d, %d]\n", r2[0], r2[1]);  /* Expected: [1, 2] */
    free(r2);

    int nums3[] = {3, 3};
    int *r3 = twoSum(nums3, 2, 6, &returnSize);
    printf("[%d, %d]\n", r3[0], r3[1]);  /* Expected: [0, 1] */
    free(r3);

    return 0;
}
