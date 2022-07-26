bool structCompare (struct val a, struct val b) {
    if (a.first != b.first) {
        return a.first<b.first;
    } else {
        return a.second<b.second;
    }
}


class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        
        vector<int> dp (n, 1);
        sort (p, p+n, structCompare);
        int res = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (p[j].second < p[i].first) {
                    dp[i] = max (dp[i], dp[j] + 1);
                }
            }
            res = max (res, dp[i]);
        }
        return res;
    }
};