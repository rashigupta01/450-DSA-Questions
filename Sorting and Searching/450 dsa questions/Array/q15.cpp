// https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

// Approach 1: starting from the last digit find the index(k) where all the elements to right of it are in descending order. 
// Now find the element to the right of k that is just greater than a[k], and swap them, now reverse the elements to the
// right of k to sort them in ascending order  
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        if(i==-1) {
            reverse(nums.begin(), nums.end());
        } else {
            int j;
            int low = i+1, high = nums.size()-1;
            while(low<=high) {
                int mid = (low+high)/2;
                if(nums[i]<nums[mid]) {
                    j=mid;
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
            swap(nums[i], nums[j]);
            cout<<i<<" "<<j;
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};