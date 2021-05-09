#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int specific_pair (int mat[][N], int n) {
    int maximum [n-1][n-1];
    int result = INT_MIN;

    for (int i=n-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {

            int m1 = mat[i+1][j+1]; 
            int m2 = i==n-2 ? INT_MIN : maximum[i+1][j];
            int m3 = j==n-2 ? INT_MIN : maximum[i][j+1];

            maximum[i][j] = max (m1, max (m2, m3));

            result = max (result, maximum[i][j]-mat[i][j]);
        }
    }

    return result;
}

int main()
{
int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << specific_pair (mat, 5);
 
    return 0;
}