// Approach 1 : kadane's algorithm
int maxSubarraySum(int arr[], int n){
    int sum=0, maxsum=0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum<=0) sum=0;
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

// Approach 2 : DP- https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
// Handles the case when all are negative
int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];
 
   for (int i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}