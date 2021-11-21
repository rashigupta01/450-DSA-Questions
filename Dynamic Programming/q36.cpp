// Brute force : consider all subarrays and find the one with minimum sum

// Approach : 
// use the same idea as of Kadane's algorithm
// cur_sum = min (cur_sum+arr[i], arr[i]);
// res = min (res, cur_sum);