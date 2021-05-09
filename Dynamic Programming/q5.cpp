// Memoization
class Solution
{
    public:
    vector<cpp_int> memo;
    //Function to find the nth catalan number.
    cpp_int findCatalanutil(int n) 
    {
        if (n==0) return 1;
        if (memo[n]!=-1) return memo[n];
        
        cpp_int ans=0;
        for (int i=0; i<n; i++) {
            ans += findCatalanutil(i) * findCatalanutil(n-1-i);
        }
        return memo[n] = ans;
    }
    
    cpp_int findCatalan (int n) {
        memo = vector<cpp_int> (n+1, -1);
        return findCatalanutil(n);
    }
};