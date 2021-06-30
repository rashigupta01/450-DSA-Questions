
// Algo : fix left col and right col then apply kadane's algo for rows between left and right col

#include <bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

void findMaxSum(int M[][COL])
{
    for (int i=0; i<ROW; i++) {
        for (int j=1; j<COL; j++) {
            M[i][j] += M[i][j-1];
        }
    }
    int max_so_far = INT_MIN;
	for (int i=0; i<COL; i++) {
        for (int j=i; j<COL; j++) {
            int rowsum = M[0][j]-(i>0 ? M[0][i-1] : 0);
            int cursum = rowsum;
            max_so_far = max (max_so_far, rowsum);
            for (int k=1; k<ROW; k++) {
                int rowsum = M[k][j]-(i>0 ? M[k][i-1] : 0);
                cursum = max (cursum + rowsum, rowsum);
                max_so_far = max (max_so_far, cursum);
            }

        }
    }
    cout << max_so_far;
}

// Driver Code
int main()
{
	int M[ROW][COL] = { { 1, 2, -1, -4, -20 },
						{ -8, -3, 4, 2, 1 },
						{ 3, 8, 10, 1, 3 },
						{ -4, -1, 1, 7, -6 } };

	// Function call
	findMaxSum(M);

	return 0;
}
