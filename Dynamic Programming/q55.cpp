// My approach
// fix left and right column now store the sum of each row 'k' for M[k][left] to M[k][right] in temp[k]
// now our task is to find the largest size subarray in temp with sum 0
// for that... prefix temp array, then keep an unordered map if a value exist in map that means sum of values between those 
// index is 0
// find the largest gap between same elements

// For code refer : https://www.geeksforgeeks.org/largest-rectangular-sub-matrix-whose-sum-0/
// or my code of ques 57
vector<vector<int>> sumZeroMatrix(vector<vector<int>> A){
    int ROW = A.size();
    int COL = A[0].size();
    vector<vector<int>> M (ROW, vector<int> (COL));
    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            if (j==0) M[i][j] = A[i][j];
            else M[i][j] = M[i][j-1] + A[i][j];
        }
    }
    int curmax = 0;
    vector<int> ans;
    for (int i=0; i<COL; i++) {
        for (int j=i; j<COL; j++) {
            int cursum = 0;
            unordered_map<int, int> m;
            m[0] = -1;
            for (int k=0; k<ROW; k++) {
                int rowsum = M[k][j]-(i>0 ? M[k][i-1] : 0);
                cursum += rowsum;
                if (m.find(cursum) != m.end()) {
                    if ((j-i+1)*(k-m[cursum]) > curmax) {
                        curmax = (j-i+1)*(k-m[cursum]);
                        ans = vector<int> {i, j, m[cursum]+1, k};
                    }
                } else {
                    m[cursum] = k;
                }
            }
        }
    }
    if (ans.size() == 0) return vector<vector<int>> ();
    vector<vector<int>> res (ans[3]-ans[2]+1);
    for (int i=ans[2]; i<=ans[3]; i++) {
        for (int j=ans[0]; j<=ans[1]; j++) {
            res[i-ans[2]].push_back(A[i][j]);
        }
    }
    return res;
}