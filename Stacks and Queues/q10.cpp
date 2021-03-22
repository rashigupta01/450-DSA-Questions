// O(n^2) approach
int celebrity(vector<vector<int> >& M, int n) {
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            sum += M[i][j];
        }
        if (sum == 0) {
            for (int j=0; j<n; j++) {
                sum += M[j][i];
            }
            if (sum == n-1) return i;
            else return -1;
        }
    }
    return -1;
}

// https://www.geeksforgeeks.org/the-celebrity-problem/
// O(n) approaches
// #1 : Reccursion - find the celeb of n-1 people, if nth person know this celeb and he do not know him return that person else -1

// #2 : Stack - push all the persons now pop two person a, b, if a know b a is not celeb else b is not celeb. repeat until only one person is left
// check if the only person left is actually a celeb

// #3 : Two pointer - same as stack but O(1) space. keep low as 0 and high as n-1. now check for low and high and reduce the search space accordingly
// lastly check if only element left is actually a celeb