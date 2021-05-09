// https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/

// O(nlogm) approach
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int count[n];
    int min_idx_so_far = m;
    for (int i=0; i<n; i++) {
        if (min_idx_so_far<m && arr[i][min_idx_so_far]==0) continue;

        int low = 0, high = m-1;
        count[i] = m;
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (arr[i][mid]) {
                count[i] = mid;
                high = mid-1;
            } else {
                low=mid+1;
            }
        }
        min_idx_so_far = count[i];
    }
    int res=-1, mn=m;
    for (int i=0; i<n; i++) {
        if (count[i] < mn) {
            mn = count[i];
            res = i;
        }
    }
    return res;
}

// Some optimization done in above code:
// Worst case : O(nlogm)
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int count[n];
    int min_idx_so_far = m;
    int res = -1;
    for (int i=0; i<n; i++) {
        count[i] = m;
        if (min_idx_so_far<m && arr[i][min_idx_so_far]==0) continue;

        int low = 0, high = min_idx_so_far-1;
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (arr[i][mid]) {
                count[i] = mid;
                high = mid-1;
            } else {
                low=mid+1;
            }
        }
        if (min_idx_so_far > count[i]) {
            min_idx_so_far = count[i];
            res = i;
        }
    }
    return res;
}


// Following method works in O(m+n) time complexity in worst case. 
// Step1: Get the index of first (or leftmost) 1 in the first row.
// Step2: Do following for every row after the first row 
// …IF the element on left of previous leftmost 1 is 0, ignore this row. 
// …ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.