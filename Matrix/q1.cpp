// 3-4 approaches covered : https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int i=0, j=0, maxr = r-1, minr = 1, maxc = c-1, minc = 0; 
        vector<int> res;
        char dir='r';
        if (maxc==0) dir = 'd';
        
        for (int k=0; k<r*c; k++) {
            res.push_back(matrix[i][j]);
            switch (dir) {
                case 'r':
                    j++;
                    if (j==maxc) {
                        dir = 'd';
                        maxc--;
                    }
                    break;
                case 'l':
                    j--;
                    if (j==minc) {
                        dir = 'u';
                        minc++;
                    }
                    break;
                case 'u':
                    i--;
                    if (i==minr) {
                        dir = 'r';
                        minr++;
                    }
                    break;
                case 'd':
                    i++;
                    if (i==maxr) {
                        dir = 'l';
                        maxr--;
                    }
                    break;
            }
        }
        return res;
    }
};

// same approach ... simplified than mine ... though contain some syntax errors ...
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
     
    if (matrix.size() == 0)
        return ans;
 
    int R = matrix.size(), C = matrix[0].size();
    bool seen[R][C];   
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int r = 0, c = 0, di = 0;
 
    // Iterate from 0 to R * C - 1
    for (int i = 0; i < R * C; i++) {
        ans.push_back(matrix[r]);
        seen[r] = true;
        int cr = r + dr[di];
        int cc = c + dc[di];
 
        if (0 <= cr && cr < R && 0 <= cc && cc < C
            && !seen[cr][cc])
        {
            r = cr;
            c = cc;
        }
        else
        {
            di = (di + 1) % 4;
            r += dr[di];
            c += dc[di];
        }
    }
    return ans;
}