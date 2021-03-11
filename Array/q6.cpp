
// Approach 1: insert all the elements of both the array in a set and return the size of set (not much creative)
int doUnion(int a[], int n, int b[], int m)  {
    unordered_set<int> s;
    for(int i=0; i<n; i++) {
        s.insert(a[i]);
    }
    for(int i=0; i<m; i++) {
        s.insert(b[i]);
    }
    return s.size();
}

// *************************************** Without using stl data structures ***************************************
// Approach 2: niave - copy elements of first array into union, for all elements 2nd array if it does not exist in union include it

// Approach 3: sort the two arrays, now find their union by two pointer approach

// Approach 4: sort the smaller array, for other array elements do the binary search in sorted array