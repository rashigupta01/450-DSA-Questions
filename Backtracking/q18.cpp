// My solution: try to find a subset with sum = tot_sum/k in the left over array
// once found reccurse for k-1
int req = 0;
bool util (int a[], bool taken[], int n, int k, int sum, int pos) {
    if (sum < 0) return false;
    if (sum==0) {
        if (k==1) {
            return true;
        } else {
            return util (a, taken, n, k-1, req, 0);
        }
    }
    for (int i=pos; i<n; i++) {
        if (!taken[i]) {
            taken[i] = true;
            if (util (a, taken, n, k, sum-a[i], i+1)) return true;
            taken[i] = false;
        }
    }
    return false;
}
bool isKPartitionPossible(int a[], int n, int k) {
    req = 0;
    for (int i=0;  i<n; i++) req += a[i];
    if (req%k) return false;
    req = req/k;
    bool taken[n] = {false};
    return util (a, taken, n, k, req, 0);
}

// Another approach : https://ide.geeksforgeeks.org/XUlEN8NliK
// include the current element in every subset one by one, and reccurse for next element