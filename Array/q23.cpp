// Approach 1: Traverse every subarrays and return the maximum product of these subarrays. (Tc-O(n^2) sc-O(1))

// Appraoch 2: https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
// Algorithm-
// 1. maintain 2 variables minsofar and maxsofar and update for each element in a for loop
// 2. if current ele is neg then for maxsofar consider current element and minsofar * current element


// Approach 3: https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity/248020
// Explaination of the approach : https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity/337552
// Algorithm-
// do two traversals of the array, once in forward dir once in backward direction.
// (basically once we are ignoring first neg no and once the last neg no)
