//? duplicates not considered

// approach 1: hashing
// hash the elements
// for each possible pair check the existance of sum-arr[i]-arr[j] 
// if exist then check if it is not same as that of the pair 
// finally return count/3

// Approach 2: two pointer approach
// fix one of the element using a for loop
// then apply two pointer approach in arr[i+1...n] to find doublet with sum "sum-arr[i]"