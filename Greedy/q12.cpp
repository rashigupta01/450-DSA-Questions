// C++ program to divide a board into m*n squares
#include <bits/stdc++.h>
using namespace std;

// v*hpiece + h*(vpiece+1), h*vpiece + v*(hpiece+1)

int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
	sort(X, X + m, greater<int>());
	sort(Y, Y + n, greater<int>());

	int hpiece = 1, vpiece = 1, cost = 0;

	int i = 0, j = 0;
	while (i < m && j < n) {
		if (X[i] > Y[j]) {
			cost += X[i] * vpiece;
			hpiece++;
			i++;
		} else {
			cost += Y[j] * hpiece;
			vpiece++;
			j++;
		}
	}

	while (i < m) cost += X[i++]*vpiece;
	while (j < n) cost += Y[j++]*hpiece;
	
	return cost;
}

// Driver code to test above methods
int main()
{
	int m = 6, n = 4;
	int X[m-1] = {2, 1, 3, 1, 4};
	int Y[n-1] = {4, 1, 2};
	cout << minimumCostOfBreaking(X, Y, m-1, n-1);
	return 0;
}
