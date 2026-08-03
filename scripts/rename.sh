#!/bin/bash
# DSA Portal — Directory Rename Script
# Run from /home/neehar/Documents/DSA on the migration branch
set -e

rename_dir() {
  local old="$1" new="$2"
  if [ -d "$old" ]; then
    git mv "$old" "$new"
    echo "✓ $old → $new"
  else
    echo "  skip (not found): $old"
  fi
}

echo "=== Renaming topic directories ==="
rename_dir Arrays             arrays
rename_dir Backtracking       backtracking
rename_dir BinarySearchTree   binary-search-tree
rename_dir BitManipulation    bit-manipulation
rename_dir DynamicProgramming dynamic-programming
rename_dir FenwickTree        fenwick-tree
rename_dir Graph              graph
rename_dir Greedy             greedy
rename_dir Hashing            hashing
rename_dir Heap               heap
rename_dir LinkedList         linked-list
rename_dir PrefixSum          prefix-sum
rename_dir Queue              queue
rename_dir Recursion          recursion
rename_dir Resources          assets
rename_dir Searching          searching
rename_dir SegmentTree        segment-tree
rename_dir SlidingWindow      sliding-window
rename_dir Sorting            sorting
rename_dir Stack              stack
rename_dir Strings            strings
rename_dir Trees              trees
rename_dir Trie               trie
rename_dir TwoPointers        two-pointers
rename_dir UnionFind          union-find
echo ""

echo "=== Renaming Easy/Medium/Hard subdirectories ==="
TOPICS="arrays backtracking binary-search-tree bit-manipulation dynamic-programming \
        fenwick-tree graph greedy hashing heap linked-list prefix-sum queue recursion \
        searching segment-tree sliding-window sorting stack strings trees trie \
        two-pointers union-find"

for topic in $TOPICS; do
  for sub in Easy Medium Hard; do
    lower=$(echo "$sub" | tr '[:upper:]' '[:lower:]')
    if [ -d "$topic/$sub" ]; then
      git mv "$topic/$sub" "$topic/$lower"
      echo "✓ $topic/$sub → $topic/$lower"
    fi
  done
done

echo ""
echo "=== All renames complete ==="
git status --short | head -60
