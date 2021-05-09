// https://www.youtube.com/watch?v=ju8vrEAsa3Q

#define MOD 1000000007
class Solution{
    public:
    long long countWays(int n, int k){
        long long K = (long long) k;
        long long  total[n+1], same[n+1], diff[n+1];
        total[0] = same[0] = diff[0] = 0;
        same[2] = K; diff[2] = K*(K-1);
        total[2] = same[2] + diff[2];
        total[1] = diff[1] = K; same[1] = 0;
        
        for (int i=3; i<=n; i++) {
            same[i] = diff[i-1];
            diff[i] = (total[i-1]*(k-1))%MOD;
            total[i] = (same[i] + diff[i])%MOD;
        }
        return total[n];
    }
};

// Optimization 1
// total[i] = same[i] + diff[i] = diff[i-1] + diff[i] = (k-1) * (total[i-2] + total[i-1])

// Optimization 2
// O(n) --> O(1) space complexity
// use of table can be avoided and only three variables could be used