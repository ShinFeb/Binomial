# DIFFICULTY:

medium

# PREREQUISITES:

partial sums, dequeue, dynamic programming

# PROBLEM:

You are given 2-D matrix $A[n][m]$. The matrix will be called good if there exists a sub-matrix (continuous rectangular block of matrix) of dimensions $a \times b$ whose all of its elements are equal. In a single operation, you can increase any element of the matrix by 1. Find out minimum number of operations required to make the matrix good.

# QUICK EXPLANATION:

For finding sum of a sub-matrix, you can use partial sums.
For finding maximum element in a sub-matrix, your can use doubly ended queue or deque.

# EXPLANATION:

Let us consider some $a \times b$ dimension sub-matrix. Let $x$ be the largest element in the sub-matrix. Let $S$ be the total sum of elements in the sub-matrix. For making all the elements equal in minimum number of operations, we should aim to make all the elements equal to $x$. So, the minimum number of operations required will be $x * n * m - S$.

So, we have to find the sum and maximum element in all the possible sub-matrices of dimension $a \times b$.

For finding sum of all sub-matrices of sizes $a \times b$, we can use maintain partial sum sub-matrix. For that, we maintain another array, $sum[n][m]$, where $sum[i][j]$ will denote the sum of elements of the sub-matrix with left top end coordinate being $(1, 1)$ and right bottom coordinate being $(i, j)$. After computing $sum$ matrix, we can find the sum of any sub-matrix.

Now let us learn about how to find maximum element in all sub-matrices of sizes $a \times b$. Let $maxCol[i][j]$ be the maximum element of the sub-matrix in the column starting at $(i, j - b + 1)$ and ending at $(i, j)$ (i.e. of column of length $b$).

Assume that we have computed $maxCol$ array efficiently, let us find how we can use this to calculate maximum of $a \times b$ sub-matrix.

Let $max[i][j]$ denote the maximum value of sub-matrix of $A$ ending at $(i, j)$ (bottom right point), and of dimensions $a \times b$. Note that $max[i][j]$ is maximum of $maxCol[i - a + 1][j], maxCol[i - a + 2][j], \dots, maxCol[i][j]$. Note that for calculating $max[i][j + 1]$ from $max[i][j]$, we have to add a new element $maxCol[i][j + 1]$ and remove the element $maxCol[i - a + 1][j]$.

That means, that we have to maintain maximum of a constant size subarray of an array, i.e. at each step, maintain maximum with inserting and deleting one element at each step. Note that we can compute $maxCol$ in similar way.

This can be done either maintaining a multi-set (balanced binary search tree) of $K$ elements, in which insertion/deletion and finding maximum can be done in $\mathcal{O}(\log n)$ time. Sadly this method is slower for passing largest subtask.

You can find a $\mathcal{O}(n)$ solution for it by using doubly ended queue (aka deque). Please see this [link](http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/) for its very detailed explanation.

# Time Complexity:

$\mathcal{O}(n m)$ for finding both $maxCol$ and $max$ matrices.