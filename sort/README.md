Pseudocode and short descriptions for each sorting algorithms:

1. Bubble Sort:

Pseudocode:

```
function bubbleSort(arr):
    n = length(arr)
    for i from 0 to n-1:
        for j from 0 to n-1-i:
            if arr[j] > arr[j+1]:
                swap(arr[j], arr[j+1])
    return arr
```

Description:
Bubble sort is a simple comparison-based sorting algorithm. It repeatedly compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

2. Heap Sort:

Pseudocode:

```
function heapSort(arr):
    buildMaxHeap(arr)
    for i from length(arr) down to 2:
        swap(arr[1], arr[i])
        heapify(arr, 1, i - 1)

function buildMaxHeap(arr):
    n = length(arr)
    for i from n/2 down to 1:
        heapify(arr, i, n)

function heapify(arr, i, n):
    largest = i
    left = 2 * i
    right = 2 * i + 1
    if left <= n and arr[left] > arr[largest]:
        largest = left
    if right <= n and arr[right] > arr[largest]:
        largest = right
    if largest != i:
        swap(arr[i], arr[largest])
        heapify(arr, largest, n)
```

Description:
Heap sort is a comparison-based sorting algorithm that uses a binary heap data structure. It first builds a max-heap from the array, which ensures that the largest element is at the root. It then repeatedly extracts the maximum element and rebuilds the max-heap until the array is sorted.

3. Insertion Sort:

Pseudocode:

```
function insertionSort(arr):
    n = length(arr)
    for i from 1 to n-1:
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = key
    return arr
```

Description:
Insertion sort is a simple sorting algorithm that builds the final sorted array one element at a time. It takes each element and inserts it into its correct position among the previously sorted elements.

4. Merge Sort:

Pseudocode:

```
function mergeSort(arr):
    if length(arr) <= 1:
        return arr

    mid = length(arr) / 2
    left = arr[0 to mid-1]
    right = arr[mid to end]

    left = mergeSort(left)
    right = mergeSort(right)

    return merge(left, right)

function merge(left, right):
    result = []
    while left is not empty and right is not empty:
        if left[0] <= right[0]:
            append left[0] to result
            remove first element from left
        else:
            append right[0] to result
            remove first element from right

    append remaining elements of left and right to result
    return result
```

Description:
Merge sort is a divide-and-conquer sorting algorithm. It divides the array into smaller subarrays, sorts them, and then merges the sorted subarrays to produce a sorted array. It is known for its stable and consistent performance.

5. Quick Sort:

Pseudocode:

```
function quickSort(arr, low, high):
    if low < high:
        pivotIndex = partition(arr, low, high)
        quickSort(arr, low, pivotIndex - 1)
        quickSort(arr, pivotIndex + 1, high)

function partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j from low to high - 1:
        if arr[j] <= pivot:
            i = i + 1
            swap arr[i] and arr[j]
    swap arr[i + 1] and arr[high]
    return i + 1
```

Description:
Quick sort is a divide-and-conquer sorting algorithm that chooses a pivot element and partitions the array into two subarrays - one with elements less than the pivot and another with elements greater than the pivot. It then recursively sorts the subarrays.

6. Selection Sort:

Pseudocode:

```
function selectionSort(arr):
    n = length(arr)
    for i from 0 to n-1:
        minIndex = i
        for j from i+1 to n-1:
            if arr[j] < arr[minIndex]:
                minIndex = j
        if minIndex != i:
            swap arr[i] and arr[minIndex]
    return arr
```

Description:
Selection sort is a simple sorting algorithm that repeatedly selects the minimum (or maximum) element from the unsorted portion of the array and places it at the beginning. It works well for small lists or when the number of swaps is a concern.
