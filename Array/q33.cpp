
// Approach 1: Sliding window and two pointer. Size of window will be count of elements <= k. For every window find the number
// of swaps. (TC-O(n) SC-O(1))
#include<limits.h>
int minSwap(int *arr, int n, int k) {
    int count=0;
    for(int i=0; i<n; i++) {
        if(arr[i]<=k) count++;
    }
    int i, lessthank=0;
    for(i=0; i<count; i++) {
        if(arr[i]<=k) lessthank++;
    }
    int result = count-lessthank;
    for(; i<n; i++) {
        if(arr[i]<=k) lessthank++;
        if(arr[i-count]<=k) lessthank--;
        result = min (result, count-lessthank);
    }
    return result;
}
