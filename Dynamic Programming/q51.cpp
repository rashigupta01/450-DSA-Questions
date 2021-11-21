// * HINT : same approach as of MCM

// ? I hate writing iterative codes for MCM problems :P

// revisit for O(N^2) approach, really great, try to code while revising : https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/

class Solution{
public:

    vector<vector<int>> dp;
    
    bool palin (string &s, int start, int end) {
        for (int i=start, j=end; i<j; i++, j--) {
            if (s[i]!=s[j]) return false;
        }
        return true;
    }
    
    int util (string &s, int i, int j) {
        
        if (i==j) return 0;
        if (dp[i][j]!=INT_MAX) return dp[i][j];
        
        if (palin(s, i, j)) return dp[i][j] = 0;
        
        int res = INT_MAX;
        for (int k = i; k<j; k++) {
            res = min (res, 1+ util (s, i, k) + util (s, k+1, j));
            // cout << "(" << i << ","<<j<<") -> " << res << endl;
        }
        return dp[i][j] = res;
    }

    int palindromicPartition(string str)
    {
        dp = vector<vector<int>> (str.size(), vector<int> (str.size(), INT_MAX));
        return util (str, 0, str.size()-1);
    }
};