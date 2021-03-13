// Heapsort:
// First of all convert the array into max heap
// Now swap the root and last element so that the largest element (root) is at the end of the array (descending order)
// Now the last element is not considered the part of the heap, hence the size of heap is decremented.
// Now the new root is not at its proper position so call heapify for root
// Repeat the process for all the elements till the heap is empty.