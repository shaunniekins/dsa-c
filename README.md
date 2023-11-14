# Data Structures and Algorithms

This repository is a comprehensive collection of data structures and algorithms using C language, inspired by the work of [msambol](https://github.com/msambol/dsa).

## Overview

The purpose of this repository is to provide a thorough understanding of some data structures and algorithms, which are fundamental to computer science and programming.

### Some of the Common Problem-Solving Approaches in Data Structures and Algorithms

**1. Brute Force:** This approach involves trying all possible solutions and selecting the one that works. It is often a simple and straightforward method but may not be efficient for large datasets.

- **Exhaustive Search**: This is a brute force approach where you try all possible combinations or solutions to find the best one. An example would be solving the Traveling Salesman Problem by considering all possible routes.

**2. Divide and Conquer:** Divide a problem into smaller subproblems, solve them recursively, and combine the results. Common algorithms using this approach include merge sort and quicksort.

- **Binary Search**: This algorithm transforms a sorted list into a simpler problem by repeatedly dividing the search interval in half, making it more efficient to find a specific element in the list.
- **Merge Sort**: A sorting algorithm that divides an array into two halves, recursively sorts them, and then merges the two sorted halves to produce a fully sorted array.
- **QuickSort**: Another sorting algorithm that chooses a pivot element, partitions the array into two subarrays, and then recursively sorts the subarrays.

**3. Greedy Algorithms:** Make a series of locally optimal choices to arrive at a globally optimal solution. Greedy algorithms are often used for optimization problems, like the Knapsack problem and Huffman coding.

- **Dijkstra's Algorithm**: Used to find the shortest path in a weighted graph by making locally optimal choices at each step.
- **Kruskal's Algorithm**: Used to find the minimum spanning tree in a graph by selecting edges in a way that minimizes the total weight of the tree.

**4. Transform and Conquer:** Transforming the original problem into a different problem that is easier to solve. After solving the easier problem, you then map the solution back to the original problem. This approach can simplify complex problems by reducing them to simpler, related problems.

- **The Fast Fourier Transform (FFT)**: Reduces the problem of polynomial multiplication to a problem of transforming polynomials into a different domain (frequency domain) and then performing point-wise multiplication.
- **Pre-Sorting**: Pre-sorting is a transformation technique where you transform a problem that involves an unsorted list into a problem involving a sorted list. Sorting the data first can simplify the subsequent operations. For example, if you want to find a specific element in an array, sorting the array first (e.g., using binary search) can make the search more efficient.
- **Gaussian Elimination**: Gaussian elimination is used to solve systems of linear equations. It transforms the system into an equivalent triangular form, making it easier to solve. This technique simplifies the problem of solving linear equations.
- **Balanced Search Tree**: Using a balanced search tree, like an AVL tree or a Red-Black tree, can transform the problem of searching for an element in an unsorted list into a problem of searching in a sorted tree structure, which is more efficient.
- **Problem Reduction**: Problem reduction is a general concept within the "Transform and Conquer" approach. It involves transforming a problem into a different problem that is easier to solve and then mapping the solution back to the original problem. This can include various reduction techniques, such as transforming graph problems into simpler graph problems, transforming decision problems into search problems, and more.

**5. Decrease and Conquer:** Decrease and conquer involves solving a problem by reducing it to a smaller instance of the same problem. You keep reducing the problem size until you reach a base case that can be solved directly. Once the base case is solved, you combine solutions to the smaller problems to solve the original problem. This is often used in recursive algorithms, where a problem is divided into smaller subproblems.

- **Factorial**: The problem of computing the factorial of a number can be solved using decrease and conquer by reducing it to a smaller instance (n-1 factorial) until reaching the base case (0 factorial).
- **Towers of Hanoi**: In this problem, you decrease the number of disks to move by moving the smaller tower until you reach the base case of moving a single disk. Then, you can solve the original problem by building the tower on top of the single disk.
