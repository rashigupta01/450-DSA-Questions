// O(n^2) : check for each bar and find the area for that bar height in O(n). return the max area

// O(nlogn) average and O(n^2) worst case : Divide and conquer, find the min element in the current array. return the max of -
// a) Maximum area in left side of minimum value (Not including the min value)
// b) Maximum area in right side of minimum value (Not including the min value)
// c) Number of bars multiplied by minimum value.

// Segment tree solution exist: https://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/
// check out after studying segment trees

// O(n) stack approach
long long getMaxArea(long long arr[], int n) {
    stack <long long> s;
    long long res=0;
    for (int i=0; i<n; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            long long cur = s.top();
            s.pop();
            long long low = s.empty() ? -1 : s.top(), high = i-1;
            res = max (res, arr[cur]*(high-low));
        }
        s.push(i);
    }
    while (!s.empty()) {
        long long cur = s.top();
        s.pop();
        long long low = s.empty() ? -1 : s.top(), high = n-1;
        res = max (res, arr[cur]*(high-low));
    }
    return res;
}