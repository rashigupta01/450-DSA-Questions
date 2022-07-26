// copy all the elements of first and second array in a separate temperary array
// perform heapify on this temperary array
// copy back it in array 'A' and rest elements in array 'B'

// O(m+n) time and space complexity

void maxHeapify(vector<int> &arr, int n, int idx)
{
    if (idx >= n) return;
    
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    
    int max;
    if (l < n && arr[l] > arr[idx])
        max = l;
    else
        max = idx;
    if (r < n && arr[r] > arr[max])
        max = r;
    
    if (max != idx) {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}
    

void buildHeap(vector<int> &a) {
    for (int i = a.size() / 2 - 1; i >= 0; i--)
        maxHeapify(a, a.size(), i);
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> res (n+m);
    for (int i=0; i<n; i++) res[i] = a[i];
    for (int j=0; j<m; j++) res [j+n] = b[j];
    buildHeap (res);
    return res;
}