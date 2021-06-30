// My approach
// fix left and right column now store the sum of each row 'k' for M[k][left] to M[k][right] in temp[k]
// now our task is to find the largest size subarray in temp with sum 0
// for that... prefix temp array, then keep an unordered map if a value exist in map that means sum of values between those 
// index is 0
// find the largest gap between same elements

// For code refer : https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/
// or my code of ques 57