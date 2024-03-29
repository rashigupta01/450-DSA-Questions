// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/

void rotate(vector<vector<int> >& matrix)
{
    int n = matrix.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            swap (matrix[i][j], matrix[j][i]);
        }
    }
    
    for (int i=0; i<n/2; i++) {
        for (int j=0; j<n; j++) {
            swap (matrix[i][j], matrix[n-i-1][j]);
        }
    }
}