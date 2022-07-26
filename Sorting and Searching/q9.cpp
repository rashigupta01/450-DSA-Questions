// Approach 1: Simple Linear Search

// Approach 2: Instead of searching linearly we can jump through unnecessary comparisions. Jump by abs(x- array[i]) /k if the
// current element is not x.
int search(int arr[], int n, int x, int k)
{
    int i=0;
    while (i<n) {
        if (arr[i] == x) return i;
        
        int gap = abs (arr[i] - x);
        i += ceil ((double)gap/k);
    }
    return -1;
}