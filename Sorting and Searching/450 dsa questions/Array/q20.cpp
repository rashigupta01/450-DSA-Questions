// Approach 1: copy +ve and -ve values in two different temp arrays and then copy them in the main array one by one. (TC-O(n) SC-O(n)) 

// Approach 2: assume that we place neg no on index 0. Now find the value that is not at its correct position. Now for this position
// find the index with opposite sign value and do right rotation. (TC-O(n^2) SC-O(1))
// a little optimization: same as approach 3, but instead of just swapping we need to do right rotation
// It is given on https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

// Approach 3: (if order is not important)
// assume that we place neg no on index 0. Now iterate through all the elements. If a value is not at its correct position store its
// index in a variable(outoforder). Now when we reach a value with opposite sign value swap it with outoforder and update
// outoforder += 2 and continue. (TC-O(n) SC-O(1))

// Approach 4: (if order is not important)
// shift all positive to starting of array and negatives at the end. then swap the alternative +ve with next available -ve element 