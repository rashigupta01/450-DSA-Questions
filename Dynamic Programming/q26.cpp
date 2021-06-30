//* "My approach": reccursion with memoization
// NOTE: in the first if i am not considering util(arr, last-1, k), since it is sorted
// if i would have considered then i should have memoized it; in the below dp approach gfg has considered that case
class Solution{
    public:
    
    int util (int arr[], int last, int K) {
        
        if (last<=0) return 0;
        if (arr[last]-arr[last-1] < K) {
            return arr[last] + arr[last-1] + util (arr, last-2, K);
        } else {
            return util (arr, last-1, K);
        }
    }
    
    int maxSumPairWithDifferenceLessThanK(int arr[], int N, int K)
    {
        sort (arr, arr+N);
        return util (arr, N-1, K);
        
    }
};

//* Approach 2: DP approach
/* 
  Pair up i with (i-1)th element, i.e. 
      dp[i] = dp[i-2] + arr[i] + arr[i-1]
  Don't pair up, i.e. 
      dp[i] = dp[i-1] 
    for each i put the max of both in dp array
*/

//* Approach 3: Greedy approach 
/*
    sort the array, scan the array in reverse order
    if there is a pair ignore the pair and add their sum in result
    otherwise i--
*/
int maxSumPair(int arr[], int N, int k)
{
    int maxSum = 0;
 
    // Sort elements to ensure every i and i-1 is closest possible pair
    sort(arr, arr + N);
 
    // To get maximum possible sum,
    // iterate from largest to
    // smallest, giving larger
    // numbers priority over smaller
    // numbers.
    for (int i = N - 1; i > 0; --i)
    {
        // Case I: Diff of arr[i] and arr[i-1]
        //  is less then K,add to maxSum      
        // Case II: Diff between arr[i] and arr[i-1] is not
        // less then K, move to next i since with
        // sorting we know, arr[i]-arr[i-1] >
        // arr[i]-arr[i-2] and so on.
        if (arr[i] - arr[i - 1] < k)
        {
            // Assuming only positive numbers.
            maxSum += arr[i];
            maxSum += arr[i - 1];
 
            // When a match is found skip this pair
            --i;
        }
    }
 
    return maxSum;
}