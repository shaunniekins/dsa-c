Pseudocode and short descriptions for each sorting algorithms:

1. Bubble Sort:

Pseudocode:

```
function bubbleSort(arr)
    n = length(arr)
    for i from 0 to n-1
        for j from 0 to n-1-i
            if arr[j] > arr[j+1]
                swap(arr[j], arr[j+1])
```

Description:
Bubble sort is a simple comparison-based sorting algorithm. It repeatedly compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

2. Heap Sort:

Pseudocode:

```
function heapSort(arr)
    buildMaxHeap(arr)
    n = length(arr)
    for i from n-1 to 0
        swap(arr[0], arr[i])
        maxHeapify(arr, 0, i)
```

Description:
Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. It first builds a max-heap from the array, which ensures that the largest element is at the root. It then repeatedly extracts the maximum element and rebuilds the max-heap until the array is sorted.

3. Insertion Sort:

Pseudocode:

```
function insertionSort(arr)
    n = length(arr)
    for i from 1 to n-1
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key
            arr[j+1] = arr[j]
            j = j - 1
        arr[j+1] = key
```

Description:
Insertion sort is a simple sorting algorithm that builds the final sorted array one element at a time. It takes each element and inserts it into its correct position among the previously sorted elements.

4. Merge Sort:

Pseudocode:

```
function mergeSort(arr)
    if length(arr) <= 1
        return arr
    mid = length(arr) / 2
    left = mergeSort(arr[0 to mid-1])
    right = mergeSort(arr[mid to end])
    return merge(left, right)
```

Description:
Merge sort is a divide-and-conquer sorting algorithm. It divides the array into smaller subarrays, sorts them, and then merges the sorted subarrays to produce a sorted array. It is known for its stable and consistent performance.

5. Quick Sort:

Pseudocode:

```
function quickSort(arr)
    if length(arr) <= 1
        return arr
    pivot = choosePivot(arr)
    left = elements in arr less than pivot
    right = elements in arr greater than pivot
    return concatenate(quickSort(left), pivot, quickSort(right))
```

Description:
Quick sort is a divide-and-conquer sorting algorithm that chooses a pivot element and partitions the array into two subarrays - one with elements less than the pivot and another with elements greater than the pivot. It then recursively sorts the subarrays.

6. Selection Sort:

Pseudocode:

```
function selectionSort(arr)
    n = length(arr)
    for i from 0 to n-1
        minIndex = i
        for j from i+1 to n-1
            if arr[j] < arr[minIndex]
                minIndex = j
        swap(arr[i], arr[minIndex])
```

Description:
Selection sort is a simple sorting algorithm that repeatedly selects the minimum (or maximum) element from the unsorted portion of the array and places it at the beginning. It works well for small lists or when the number of swaps is a concern.
