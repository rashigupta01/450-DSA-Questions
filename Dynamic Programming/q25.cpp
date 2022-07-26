int maxSquare(int n, int m, vector<vector<int>> mat){
    int res = 0;
    for(int i = 0; i < n; i++) 
    { 
        for(int j = 0; j < m; j++) 
        { 
            if(i!=0 && j!=0 && mat[i][j] == 1) 
                mat[i][j] = min({mat[i][j-1], mat[i-1][j], 
                            mat[i-1][j-1]}) + 1; //better of using min in case of arguments more than 2
            res = max (res, mat[i][j]); 
        }
    } 
    return res;
} 