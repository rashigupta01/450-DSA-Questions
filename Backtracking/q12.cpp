class Solution 
{
    public:
    vector<vector<int>> result;
    void util (vector<int> &A, int B, vector<int> &cur, int pos) {
        if (B==0) {
            result.push_back(cur);
            return;
        }
        if (B<0) return;
        if (pos==A.size()) return;
        
        cur.push_back(A[pos]);
        util (A, B-A[pos], cur, pos);
        cur.pop_back();
        util(A, B, cur, pos+1);
        
    }
    vector<int> remove_duplicates (vector<int> A) {
        vector<int> res;
        for (int i=0; i<A.size(); i++) {
            res.push_back(A[i]);
            while (i<A.size()-1 && A[i+1] == A[i]) {
                i++;
            }
        }
        return res;
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<int> cur;
        sort (A.begin(), A.end());
        A = remove_duplicates (A);
        util (A, B, cur, 0);
        return result;
    }
};