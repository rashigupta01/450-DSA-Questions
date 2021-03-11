// https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

#include<bits/stdc++.h>
using namespace std;

// Kadane's algorithm
int maxSubarraySum(int arr[], int n){
    int sum=0, maxsum=0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum<=0) sum=0;
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}