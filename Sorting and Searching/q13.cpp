// Consider an array {4, 6, 8, 12, 15, 18, 20} with sum = 29. The outer most loop will fix the i (1st element), 
// so in the first iteration we have fixed one of our element to be 4. Now we need to find the pairs whose sum 
// is less than 25. Starting with j=1, k=6; 6+20=26>25, this pair do not contribute to ans so k--. j=1, k=5; 6+18=24<25, 
// now observe that along with {6, 18}; sum of pairs {6, 15}, {6, 12} and {6, 8} is also less than 25. So with i and j 
// fixed their are k-j (5-1=4 in this case) triplets.
long long countTriplets(long long arr[], int n, long long sum) {
    sort (arr, arr+n);
    int count = 0;
    
    for (int i=0; i<n-2; i++) {
        int low = i+1, high = n-1, target = sum-arr[i];
        while (low<high) {
            if (arr[low]+arr[high] < sum-arr[i]){
                count+=high-low;
                low++;
            } else {
                high--;
            }
        }
    }
    return count;
}