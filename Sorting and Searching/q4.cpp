#include<bits/stdc++.h>
using namespace std;
// Approach 1: Linear Search untill i*i<=n

// Approach 2: Binary Search
int squareRoot (int n) {
    int low = 1, high = n-1, ans=0;
    while(low<high) {
        int mid = (low+high)/2;
        if(mid*mid == n) return mid;
        else if (mid*mid < n) {
            low = mid+1;
            ans = mid;
        }
        else high = mid-1;
    }
    return ans;
}