// My dp approach : O (n^2) 
bool cmp (vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int> dp (pairs.size());
        sort (pairs.begin(), pairs.end(), cmp);
        dp[0] = 1;
        for (int i=1; i<pairs.size(); i++) {
            int j = i-1;
            
            while (j>=0 && pairs[j][1]>=pairs[i][0]) j--;
            dp[i] = max (dp[i-1], j<0? 1 : (dp[j]+1));
        }
        return dp[pairs.size()-1];
    }
};

// Efficient - Greedy approach : O(nlogn)
// https://leetcode.com/problems/maximum-length-of-pair-chain/discuss/105607/4-Liner-Python-Greedy/585095