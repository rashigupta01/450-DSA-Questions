// C++ program for Knight Tour problem
#include <bits/stdc++.h>
using namespace std;

#define mx 10

void printMatrix (int mat[mx][mx], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

bool util (int solution[mx][mx], int n, int i, int j, int turn) {
    // cout << i << " " << j << "| ";
    static vector<vector<int>> move = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    if (turn==n*n) {
        printMatrix(solution, n);
        return true;
    }

    if (i<0 || i>=n || j<0 || j>=n || solution[i][j]!=-1) return false;

    solution[i][j] = turn;
    for (int m=0; m<move.size(); m++) {
        if (util(solution, n, i+move[m][0], j+move[m][1], turn+1)) return true;
    } 
    solution[i][j] = -1;
    return false;
}

void solveKT (int n) {
    int solution [mx][mx];
    memset(solution, -1, sizeof(solution));

    if (!util (solution, n, 0, 0, 0)) {
        cout << "NO SOLUTION";
    }
}

// Driver Code
int main()
{
    int n; 
    cin>>n; 

	// Function Call
	solveKT(n);
	return 0;
}

// This code is contributed by ShubhamCoder
