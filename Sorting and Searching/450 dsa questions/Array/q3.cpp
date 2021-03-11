// return kth largest element

#include <bits/stdc++.h>
using namespace std;

// Approach 1: sort the array and return kth element from end. Time complexity : O(nlogn)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// Approach 2: create a max heap and and call extraxt max k times. Time complexity : O(n + kLogn)
class Solution {
public:
    void heapify(vector<int> &nums, int pos, int size) {
        int left = 2*pos + 1, right = 2*pos + 2, maxele = pos;
        if(left<size && nums[left]>nums[pos]) {
            maxele = left;
        } if(right<size && nums[right] > nums[maxele]) {
            maxele = right;
        } if (maxele!=pos) {
            swap(nums[maxele], nums[pos]);
            heapify(nums, maxele, size);
        }
    }
    int extract_max(vector<int> &nums, int &size) {
        size--;
       swap(nums[0], nums[size]); 
       heapify(nums, 0, size);
       return nums[size];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int curMax;
        int size = nums.size();
        for(int i=nums.size()-1; i>=0; i--)
            heapify(nums, i, size);
        for (int i=0; i<k; i++) {
            curMax = extract_max(nums, size);
        }
        return curMax;
    }
}; 


// Approach 3: Build a Min-Heap of first k elements. after the k’th element if it is more than the root then make it root and call heapify Else ignore it.
// Time complexity: O((n-k)*logk)
void addintoheap (int minheap[], int k, int val) {
    minheap[k] = val;
    int i = k;
    while(i>0 && minheap[(i-1)/2]>minheap[i]) {
        swap(minheap[(i-1)/2], minheap[i]);
        i=i/2;
    }
}

void replacemax (int minheap[], int k, int val) {
    
    minheap[0] = val;
    int i = 0, swapwith;
    while(i<=(k-1)/2) {
        swapwith=i;
        if(minheap[2*i+1] < minheap[i]) {
            swapwith=2*i+1;
        } if (minheap[2*i+2] < minheap[swapwith]) {
            swapwith = 2*i+2;
        }
        
        if(swapwith == i) {
            break;
        } else {
            swap(minheap[i], minheap[swapwith]);
        }
        i=swapwith;
    }
}

int kthSmallest(int arr[], int l, int r, int k) {
    int minheap[k], i;
    
    for(i=0; i<k; i++) {
        // insert arr[i] into minheap
        addintoheap(minheap, i, arr[i]);
    }
    
    for(; i<=r; i++) {
        if(arr[i]>minheap[0]) {
            replacemax(minheap, k, arr[i]);
            // delete minheap[0]
            // insert arr[i] into minheap
        }
    }
    return minheap[0];
}

// Approach 4: Quick Select - Pick a pivot element, move it to its correct position and partition the array around it. 
// Stop at the point where pivot itself is k’th smallest element. Recur for one of sides of the pivot according to the position of it. 
// Worst case TC - O(n^2), Average TC - O(n) 

// Approach 5: Random Select - Modification of previous approach
// In this instead of selecting a fixed position as pivot, a random index is selected as pivot. Rest process is same

// Approach 6: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/
// Idea is to find pivot which will partition the array in a balanced form