#include <bits/stdc++.h>
using namespace std;

// Approach : if left element is less then merge the left elements else merge the right elements
int findMinOps(int arr[], int i, int j)
{
    if(i>=j) return 0;

	if (arr[i] == arr[j]) return findMinOps(arr, i+1, j-1);

    else if (arr[i] > arr[j]) {
		arr[j-1] += arr[j] ;
		return (1 + findMinOps(arr, i, j-1));
	}

	else {
		arr[i+1] += arr[i] ;
		return (1 + findMinOps(arr, i+1, j));
	}
}

// Driver program to test above
int main()
{
	int arr[] = {1, 4, 5, 9, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of minimum operations is "
		<< findMinOps(arr, 0, n-1) << endl;
	return 0;
}
