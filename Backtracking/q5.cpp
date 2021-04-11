bool SolveSudoku (int grid[N][N]) {
    
    vector<vector<bool>> rows(9, vector<bool> (9, false));
    vector<vector<int>> coloumns(9, vector<bool> (9, false));
    vector<vector<int>> boxes(9, vector<bool> (9, false));
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            
            if (grid[i][j]==0) continue;
            
            if (rows[i][grid[i][j]-1]) return false;
            rows[i][grid[i][j]-1] = true;
            
            if (coloumns[j][grid[i][j]-1]) return false;
            coloumns[j][grid[i][j]-1] = true;

            if (boxes[3*(i/3) + j/3][grid[i][j]-1]) return false;
            boxes[3*(i/3) + j/3][grid[i][j]-1] = true;
        }
    }
    
    return SolveSudokuUtil (grid, rows, coloumns, boxes, 0, 0);
}

bool SolveSudokuUtil(int grid[N][N], vector<vector<bool>> &rows, vector<vector<bool>> &coloumns, vector<vector<bool>> boxes, int row, int col)  
{ 
    if (col>8 || row>8) return true;
    if (grid[row][col]) {
        col++;
        return SolveSudokuUtil(grid, rows, coloumns, boxes, row+(col/9), col%9);
    }
    for (int i=0; i<9; i++) {
        if (rows[row][i] || coloumns[col][i] || boxes[(row/3)*3 + col/3][i]) continue;
        
        grid[row][col] = i+1;
        rows[row][i] = 1;
        coloumns[col][i] = 1;
        boxes[(row/3)*3 + col/3][i] = 1;
        
        if (SolveSudokuUtil (grid, rows, coloumns, boxes, row+((col+1)/9), (col+1)%9)) return true;
        
        // backtrack
        grid[row][col] = 0;
        rows[row][i] = 0;
        coloumns[col][i] = 0;
        boxes[(row/3)*3 + col/3][i] = 0;
    }
    
    return false;
}

void printGrid (int grid[N][N]) 
{
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout<<grid[i][j] <<" ";
        }
    }
}