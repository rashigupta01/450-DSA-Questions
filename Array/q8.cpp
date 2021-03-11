#include<bits/stdc++.h>
using namespace std;

// kadane's algorithm
int maxSubarraySum(int arr[], int n){
    int sum=0, maxsum=0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        if(sum<=0) sum=0;
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}