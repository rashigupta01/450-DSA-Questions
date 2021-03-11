// Bit masking approach: https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/ (second approach)
// maintain 3 bitsets, 1 for coloumn, 1 for right to left diagonals, 1 for left to right diagonals
// size of diagonal bitsets will be 2n-1, right to left will be represented by sum of row and coloumn
// left to right will be represented by difference of row and coloumn
// A position is safe if no queen is placed at that coloumn and left and right diagonal
// This will take O(1) time instead of conventional O(n)

// Time Complexity : O(n!)
// Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

ofstream outfile ("out.txt");

// method to find the next possible value for queen at kth row 
void next_value (int n, int k, vector<int> &x) {        // O(n) worst case
    
    while (true) {
        x[k] = (x[k]+1) % (n+1);
        if (!x[k]) return;

        bool is_safe = true;
        for (int i=0; i<k; i++) {

            // checking coloumn or diagonal attack
            if (x[k] == x[i] || k-i == abs(x[k]-x[i])) {
                is_safe = false;
                break;
            }
        }
        if (is_safe) return;
    }
}

// general backtrack reccursive method to find queen's position for each row
void general_backtrack (int n, int k, vector<int> &x) {
    
    while (true) {
        next_value(n, k, x);

        // no position is possible for queen at kth row
        if (!x[k]) {
            // backtrack
            break;
        }

        // All the queens have been assigned positions
        if (k == n-1) {
            for (int i=0; i<n; i++) {
                outfile << x[i] << " ";
            }
            outfile << endl;
        } 
        
        // reccurse for next position
        else {
            general_backtrack(n, k+1, x);
        }
    }
}

/* Driver code*/
int main() {

    int t;
    ifstream infile ("in.txt");
    if (!infile) {
        cout<<"Input file is missing";
        return -1;
    }
    infile >> t;

	while(t--) {
	    
        int n;      // size of chessboard (n x n)
        infile>>n;

        vector<int> position_of_queens(n, 0);
        general_backtrack(n, 0, position_of_queens);

        outfile << endl;
	}

	return 0;
}
