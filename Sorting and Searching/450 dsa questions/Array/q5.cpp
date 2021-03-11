#include <bits/stdc++.h>
using namespace std;

// Approach 1: two pointer approach- find the first neg value and last pos value, swap them, do untill p1<p2
void rearrange(vector<int> &a, int n) {
    int i=0, j=n-1;
    while (i<=j) {
        if(a[i]<0) {
            i++;
            continue;
        }
        if(a[j]>=0) {
            j--;
            continue;
        }
        swap(a[i], a[j]);
    }
    
}

// Approach 2: apply partition process of quicksort considering pivot value as 0

// ****************************************************************************************************************************
// **************************** Follow up ques:: order of occurance should be maintained **************************************
// ****************************************************************************************************************************

// Approach 1: Copy all elements to new array. Then copy all negative and positive elements back in original array one by one. 
// ## This approach uses auxillary space

// Approach 2: iterate all elements, if curr element is neg do right shift of positive elements by one. (TC-O(n^2))

// Approach 3: Optimized Merge Sort
// Modify Merge method of standard merge sort algorithm. While merging two sorted halves, merge in such a way that negative part
// of left and right sub-array is copied first followed by positive part of left and right sub-array.
// ###### Auxiliary array is being used for merging. Do merging in-place without using any data-structure. ######
// We need to convert [Ln Lp Rn Rp] to [Ln Rn Lp Rp] without using extra space.
/* 1. Reverse Lp and Rn. We get [Lp] -> [Lp'] and [Rn] -> [Rn'] 
    [Ln Lp Rn Rp] -> [Ln Lp’ Rn’ Rp]

   2. Reverse [Lp’ Rn’]. We get [Rn Lp].
    [Ln Lp’ Rn’ Rp] -> [Ln Rn Lp Rp]    */