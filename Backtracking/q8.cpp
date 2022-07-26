// https://www.geeksforgeeks.org/subset-sum-backtracking-4/

bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector<vector<bool>> v (n+1, vector<bool> (sum+1));
    for (int i=0; i<=n; i++) {
        v[i][0] = true;
    } 
    for (int i=1; i<=sum; i++) {
        v[0][i] = false;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=sum; j++) {
            if (arr[i-1] <= j) {
                v[i][j] = v[i-1][j-arr[i-1]] || v[i-1][j];
            } else {
                v[i][j] = v[i-1][j];
            }
        }
    }
    return v[n][sum];
}