// reccursion with memoization
class Solution{
public:
    vector<vector<int>> v;
    
    bool util (int sum, int arr[], int n) {

        if (sum == 0) return true;
        if (n==0) return false;
        
        if (v[n][sum] != -1) return v[n][sum];
        
        if (arr[n-1] <= sum) {
            return v[n][sum] = util(sum-arr[n-1], arr, n-1) || util (sum, arr, n-1);
        } else {
            return v[n][sum] = util (sum, arr, n-1);
        }
    }
    
    bool subsetSum (int sum, int arr[], int n) { 
        v = vector<vector<int>> (n+1, vector<int> (sum+1, -1));
        return util (sum, arr, n);
    }
    
    int equalPartition (int N, int arr[]) {
        long long int sum=0;
        for (int i=0; i<N; i++) sum += (long long int)arr[i];
        if (sum&1) return false;
        // cout << " c ";
        return subsetSum (sum/2, arr, N);
    }
};

// tabulation approach
class Solution{
public:
    bool subsetSum (int sum, int arr[], int n) { 
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
    
    int equalPartition (int N, int arr[]) {
        long long int sum=0;
        for (int i=0; i<N; i++) sum += (long long int)arr[i];
        if (sum&1) return false;
        return subsetSum (sum/2, arr, N);
    }
};