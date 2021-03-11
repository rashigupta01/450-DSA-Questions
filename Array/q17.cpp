#include<bits/stdc++.h>
using namespace std;

// Approach 1: keep a variable with minimum so far and find the maximum difference
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = 10001, result = 0;
        for(int i=0; i<prices.size(); i++) {
            result = max(result, prices[i]-minTillNow);
            minTillNow = min(minTillNow, prices[i]);
        }
        return result;
    }
};

// Approach 2: convert the array to store the differece between consecutive difference. Find maximum subarray
// using kadane's algorithm. Return sum.