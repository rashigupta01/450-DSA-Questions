// Approach 1 : memoize (recursion) : O(n*n)
// DP[i, j] = 1+ (min(countRemovals(i+1, j), countRemovals(i, j-1))

// Approach 2: sort + binary search : O(nlogn)
// sort the array. for each element find  maximum element on its right such that arr[j] – arr[i] <= k using binary search.

// Approach 3: sort + use two pointer or dp array such that for calculation the required element for ith we can use the
// index found for i-1th
