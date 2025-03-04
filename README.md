# Sorting Algorithm Comparison

This repository contains a Python program that implements and compares the performance of three basic sorting algorithms—Bubble Sort, Insertion Sort, and Selection Sort—with Python’s built-in sort (Timsort). The program measures the time taken by each algorithm to sort arrays of random integers of varying sizes, providing a clear demonstration of the efficiency differences between quadratic time algorithms and the more optimal O(n log n) Timsort.

## Overview

- **Bubble Sort:** Repeatedly compares and swaps adjacent elements to "bubble" the largest element to the end.
- **Insertion Sort:** Builds the sorted list one element at a time by inserting each new element into its correct position.
- **Selection Sort:** Finds the smallest unsorted element and swaps it into its correct position.
- **Timsort (Built-in):** Python’s built-in sort function, which is a hybrid of merge sort and insertion sort, optimized for real-world data.

## Files

- `sorting_comparison.py` — The main Python script containing the sorting algorithms and the performance comparison code.

## Requirements

- Python 3.x

No external libraries are needed as the program uses Python's standard `random` and `time` modules.

## How to Run

1. **Clone the repository:**
   ```bash
   git clone [<repository-url>](https://github.com/jaivarshanv/sorting-/blob/main/sorting_comparison.py)
