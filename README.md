# DSA Portal

> A documentation-first Data Structures & Algorithms learning platform —
> structured like a textbook, implemented in Python and C.

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Python](https://img.shields.io/badge/Python-3.x-3776AB?logo=python&logoColor=white)](https://python.org)
[![C](https://img.shields.io/badge/C-C11-A8B9CC?logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C11_(C_standard_revision))
[![MkDocs](https://img.shields.io/badge/Docs-MkDocs%20Material-526CFE?logo=materialformkdocs&logoColor=white)](https://squidfunk.github.io/mkdocs-material/)
[![GitHub Pages](https://img.shields.io/badge/Site-GitHub%20Pages-222?logo=github)](https://neehar2601.github.io/DSA)

---

## What This Is

This repository is **not** a collection of unrelated solution files.

It is a structured learning platform where:

- Every **topic** gets a textbook-quality explanation with theory, complexity tables, and patterns.
- Every **problem** gets its own directory with a full write-up (intuition → brute force → optimal → dry run) alongside Python and C implementations.
- The **website** mirrors the repository structure exactly — browse on GitHub or on the docs site.

---

## Repository Structure

```
DSA/
├── arrays/                     ← Topic directory
│   ├── README.md               ← Theory, patterns, complexity, problem index
│   ├── easy/
│   │   └── LC0001-two-sum/     ← Problem directory
│   │       ├── README.md       ← Full problem write-up
│   │       ├── python/
│   │       │   ├── solution.py
│   │       │   └── test_solution.py
│   │       └── c/
│   │           └── solution.c
│   ├── medium/
│   └── hard/
│
├── strings/
├── hashing/
├── linked-list/
├── stack/
├── queue/
├── trees/
├── binary-search-tree/
├── heap/
├── trie/
├── graph/
├── recursion/
├── searching/
├── sorting/
├── sliding-window/
├── two-pointers/
├── prefix-sum/
├── greedy/
├── backtracking/
├── dynamic-programming/
├── bit-manipulation/
├── segment-tree/
├── fenwick-tree/
├── union-find/
│
├── templates/                  ← Copy-paste templates for new topics/problems
├── scripts/                    ← Automation utilities
├── assets/                     ← Diagrams and shared media
│
├── mkdocs.yml                  ← Documentation site config
├── requirements.txt
└── .github/workflows/deploy.yml ← Auto-deploy to GitHub Pages
```

---

## Problem Naming Convention

All problems follow the format: `<PLATFORM><ID>-<problem-slug>/`

| Prefix | Platform |
|--------|----------|
| `LC` | LeetCode |
| `GFG` | GeeksforGeeks |
| `HR` | HackerRank |

Examples: `LC0001-two-sum/`, `LC0015-3sum/`, `GFG-reverse-linked-list/`

---

## Progress

| Topic | Easy | Medium | Hard | Status |
|-------|------|--------|------|--------|
| Arrays | 1 | 0 | 0 | 🟡 In Progress |
| Strings | 0 | 0 | 0 | ⬜ Not Started |
| Hashing | 0 | 0 | 0 | ⬜ Not Started |
| Recursion | 0 | 0 | 0 | ⬜ Not Started |
| Searching | 0 | 0 | 0 | ⬜ Not Started |
| Sorting | 0 | 0 | 0 | ⬜ Not Started |
| Linked List | 0 | 0 | 0 | ⬜ Not Started |
| Stack | 0 | 0 | 0 | ⬜ Not Started |
| Queue | 0 | 0 | 0 | ⬜ Not Started |
| Trees | 0 | 0 | 0 | ⬜ Not Started |
| Binary Search Tree | 0 | 0 | 0 | ⬜ Not Started |
| Heap | 0 | 0 | 0 | ⬜ Not Started |
| Trie | 0 | 0 | 0 | ⬜ Not Started |
| Graph | 0 | 0 | 0 | ⬜ Not Started |
| Sliding Window | 0 | 0 | 0 | ⬜ Not Started |
| Two Pointers | 0 | 0 | 0 | ⬜ Not Started |
| Prefix Sum | 0 | 0 | 0 | ⬜ Not Started |
| Greedy | 0 | 0 | 0 | ⬜ Not Started |
| Backtracking | 0 | 0 | 0 | ⬜ Not Started |
| Dynamic Programming | 0 | 0 | 0 | ⬜ Not Started |
| Bit Manipulation | 0 | 0 | 0 | ⬜ Not Started |
| Segment Tree | 0 | 0 | 0 | ⬜ Not Started |
| Fenwick Tree | 0 | 0 | 0 | ⬜ Not Started |
| Union Find | 0 | 0 | 0 | ⬜ Not Started |

---

## Quick Start

### Browse on GitHub

Click into any topic directory. GitHub renders `README.md` automatically.

### Run the docs site locally

```bash
pip install -r requirements.txt
mkdocs serve
# Open http://127.0.0.1:8000
```

### Run tests

```bash
cd arrays/easy/LC0001-two-sum/python
python -m pytest test_solution.py -v
```

### Compile a C solution

```bash
cd arrays/easy/LC0001-two-sum/c
gcc -Wall -o solution solution.c && ./solution
```

### Add a new problem

```bash
# 1. Create the directory
mkdir -p arrays/easy/LC0121-best-time-to-buy-and-sell-stock/{python,c}

# 2. Copy templates
cp templates/problem-readme.md arrays/easy/LC0121-best-time-to-buy-and-sell-stock/README.md
cp templates/solution.py        arrays/easy/LC0121-best-time-to-buy-and-sell-stock/python/solution.py
cp templates/solution.c         arrays/easy/LC0121-best-time-to-buy-and-sell-stock/c/solution.c

# 3. Fill in templates, write tests
# 4. Update arrays/README.md problem index table
# 5. Update mkdocs.yml nav section
```

---

## Philosophy

This project is not about memorizing solutions.

It is about understanding **why** a particular approach is correct, **when** a pattern applies, and **how** to communicate that reasoning clearly in code and documentation.

Every problem answer must answer:

1. What is the brute force? Why does it fail?
2. What is the insight that enables a better solution?
3. What is the exact complexity and why?

---

## Roadmap

| Phase | Description | Status |
|-------|-------------|--------|
| 1 | Repository structure + MkDocs setup + GitHub Pages | ✅ Done |
| 2 | Arrays topic complete (Easy + Medium) | 🟡 In Progress |
| 3 | Strings, Hashing, Recursion, Sorting, Searching | ⬜ Planned |
| 4 | Linear structures (Linked List, Stack, Queue) | ⬜ Planned |
| 5 | Trees, BST, Heap, Trie, Graph | ⬜ Planned |
| 6 | Interview patterns, cheat sheets, company collections | ⬜ Planned |
| 7 | Automation: auto progress tracker, index generation | ⬜ Planned |

---

## Languages

| Language | Status |
|----------|--------|
| Python | ✅ Active |
| C | ✅ Active |
| C++ | 🔜 Planned |
| Java | 🔜 Planned |

---

## License

[MIT](LICENSE) — use freely for learning.
