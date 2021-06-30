/*

1. sort the array
2. take window of size M and find the diff of A[i] and A[i+M-1] and return min of these

*/

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort (a.begin(), a.end());
        long long res = INT_MAX;
        for (long long i=0; i+m-1<n; i++) {
            res = min (res, a[i+m-1]-a[i]);
        }
        return res;
    }   
};