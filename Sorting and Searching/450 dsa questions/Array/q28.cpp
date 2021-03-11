
// Approach 1: Niave approach - in three nested loops check all possible triplets. (TC-O(n^3) SC-O(1))

// Approach 2: Hash all the elements. In two nested loops check if X-arr[i]-arr[j] exists. (TC-O(n^3) SC-O(n))

// Approach 2: sort the array, now for each element find a pair whose sum is X-arr[i]. (TC-O(n^2) SC-O(1))
bool find3Numbers(int arr[], int n, int X)
{
    sort(arr, arr+n);
    for(int i=0; i<n; i++) {
        int low=i+1, high = n-1;
        int sum = X-arr[i];
        while(low<high) {
            if(arr[low] + arr[high] == sum) {
                return true;
            } else if (arr[low] + arr[high] < sum) {
                low++;
            } else {
                high--;
            }
        }
    }
    return false;
}