// https://www.geeksforgeeks.org/merge-k-sorted-arrays/

/*

Alternative Efficient Approach: The idea is to use Min Heap. This MinHeap based solution has the same time complexity which 
is O(NK log K). But for a different and particular sized array, this solution works much better. The process must start with 
creating a MinHeap and inserting the first element of all the k arrays. Remove the root element of Minheap and put it in the 
output array and insert the next element from the array of removed element. To get the result the step must continue until 
there is no element in the MinHeap left. 

*/