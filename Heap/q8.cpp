/*

use two nested loop to go through every possible contiguous subarray ---> O(n*n)
Now store first K sums in a min heap, then check if curr sum is greater than root, 
insert in min heap with popping top element ----> O(logn)
At the end the top element in the min-heap will be your answer.

Total complexity ---> O(n*n*logn)

*/