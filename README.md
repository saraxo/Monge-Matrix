# Monge-Matrix
Data structures and algorithms project - Monge Matrix

This was my uni project for the "Data structures and algorithms" course. My task was to create a class InteresantnaMatrica with two functions. 
The theme was Monge Array or better Monge matrix.

A matrix is a Monge array if and only if for all 1 ≤ i ≤ m-1 and all 1 ≤ j ≤ n-1 we have that A[i,j] + A[i+1,j+1] ≤ A[i,j+1] + A[i+1,j]. We denote with ti (i = 1,2, ... , m) the column in which the minimum element in the ith row is located. It can be proven that ti1 ≤ ti2 ≤ ⋯ ≤ tim, i.e. if we were to round off the minimum element in each row, the rounded elements would be located in the same column as the previous one or to the right of it as we move down the rows. 

Example for the Monge matrix,

![monge](https://user-images.githubusercontent.com/129538263/229367694-586dadc0-5b81-4a78-9356-d0d17a0a15ee.jpg)


Implement function bool isMongeArray(vector>&matrix) which checks if matrix Monge or not.
Second function is vectorMinmumIndex() which return vector (t1,t2,..,tm). So,its return index of the minimum element of every row in the matrix. Use a divide-and-conquer strategy. The algorithm first recursively calls itself on the submatrix consisting only of the even rows of the original matrix. Then, in time O(m + n), it determines the minimum elements in the odd rows. Calculate the time complexity for this algorithm. 

