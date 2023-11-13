Pseudocode and short descriptions for each search algorithms:

1. Binary Search:

Pseudocode:

```
function binarySearch(arr, target)
    left = 0
    right = length(arr) - 1
    while left <= right
        mid = (left + right) / 2
        if arr[mid] == target
            return mid
        else if arr[mid] < target
            left = mid + 1
        else
            right = mid - 1
    return -1  // Element not found
```

Description:
Binary search is a fast search algorithm for sorted arrays. It repeatedly divides the search interval in half, eliminating half of the elements with each comparison. It's efficient and has a time complexity of O(log n).

2. Breadth-First Search (BFS):

Pseudocode:

```
function BFS(graph, start)
    queue = createEmptyQueue()
    visited = createEmptySet()
    enqueue(queue, start)
    while queue is not empty
        node = dequeue(queue)
        if node is not in visited
            mark node as visited
            process node
            for each neighbor of node
                if neighbor is not in visited
                    enqueue(queue, neighbor)
```

Description:
Breadth-First Search is a graph traversal algorithm that explores all the nodes at the current level before moving to the next level. It's often used to find the shortest path in unweighted graphs and can be implemented using a queue data structure.

3. Depth-First Search (DFS):

Pseudocode:

```
function DFS(graph, node)
    if node is not visited
        mark node as visited
        process node
        for each neighbor of node
            if neighbor is not visited
                DFS(graph, neighbor)
```

Description:
Depth-First Search is a graph traversal algorithm that explores as far down a branch as possible before backtracking. It's used to explore connected components in graphs and can be implemented using recursion or a stack data structure.
