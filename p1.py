import random
import time

def bubble_sort(arr):
    """Sorts the list using Bubble Sort."""
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

def insertion_sort(arr):
    """Sorts the list using Insertion Sort."""
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr

def selection_sort(arr):
    """Sorts the list using Selection Sort."""
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i+1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

def measure_time(sort_function, data):
    """Helper function to measure the runtime of a sorting algorithm."""
    start_time = time.time()
    sort_function(data)
    return time.time() - start_time

if __name__ == "__main__":
    array_sizes = [100, 200, 500]
    for size in array_sizes:
        print(f"Array size: {size}")
        original = [random.randint(0, 1000) for _ in range(size)]
        data = original.copy()
        bubble_time = measure_time(bubble_sort, data)
        data = original.copy()
        insertion_time = measure_time(insertion_sort, data)
        data = original.copy()
        selection_time = measure_time(selection_sort, data)
        data = original.copy()
        start_time = time.time()
        data.sort()
        python_time = time.time() - start_time
        print(f"  Bubble sort time:   {bubble_time:.10f} seconds")
        print(f"  Insertion sort time:{insertion_time:.10f} seconds")
        print(f"  Selection sort time:{selection_time:.10f} seconds")
        print(f"  Python built-in sort time: {python_time:.10f} seconds")
        print("-" * 50)

# This program implements three simple sorting algorithms (Bubble Sort, Insertion Sort, and Selection Sort) and compares their performance with Python’s built-in Timsort by measuring the time taken to sort arrays of various sizes, illustrating the efficiency differences between quadratic time (O(n^2)) simple sorts and the more optimal O(n log n) Timsort.
