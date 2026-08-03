#!/usr/bin/env python3
"""
cleanup.py — Remove stale files from pre-migration structure.
Run from the repo root: python3 scripts/cleanup.py
"""
import os
import glob

BASE = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

stale = [
    "arrays/easy/two_sum.py",
    "arrays/easy/test_two_sum.py",
    "arrays/Notes.md",
]

for rel in stale:
    path = os.path.join(BASE, rel)
    try:
        os.remove(path)
        print(f"removed: {rel}")
    except FileNotFoundError:
        print(f"skip (not found): {rel}")

# Remove all leftover Notes.md stubs
for path in glob.glob(os.path.join(BASE, "**/Notes.md"), recursive=True):
    if "/.git/" in path:
        continue
    os.remove(path)
    print(f"removed: {os.path.relpath(path, BASE)}")

print("cleanup complete")
