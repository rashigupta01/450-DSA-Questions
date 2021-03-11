// Approach 1: Niave approach- In two nested loops, check the sum of all possible subarrays. (TC-O(n^2))

// Approach 2: two pointer approach- refer code below. (TC-O(n))
int sb(int arr[], int n, int x)
{
    int sum=0, i=0, j=-1, minsubarray=n+1;
    while(1) {
        if(sum > x) {
            if(j-i+1 < minsubarray) {
                minsubarray = j-i+1;
            }
            sum-=arr[i];
            i++;
        } else {
            if(j==n-1) break;
            j++;
            sum+=arr[j];
        }
    }
    return minsubarray;
}