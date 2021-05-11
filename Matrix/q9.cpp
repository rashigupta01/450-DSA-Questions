// idea of q5 could be used : O(klogn + n)

// used the idea of question 3 : O(n logm log(mx-mn)) [efficient]
int kthSmallest(int m[MAX][MAX], int n, int k)
{
    int mn = m[0][0], mx = INT_MIN;
    for (int i=0; i<n; i++) mx = max (mx, mat[i][n-1]);
    
    int desired = k;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int place = 0;
  
        // Find count of elements smaller than mid
        for (int i = 0; i < n; ++i)
            place += upper_bound(m[i], m[i]+n, mid) - m[i];
        if (place < desired)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}