// Approach 1: Linear Search. (TC-O(n))

// Approach 2: Binary Search. (TC-O(logn))
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    int ans=-1;
    int low = 0, high = nums.size()-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(nums[mid]==target) {
            ans=mid;
            high=mid-1;
        } else if (nums[mid]<target) {
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    res.push_back(ans);
    
    ans=-1;
    low = 0; high = nums.size()-1;
    while(low<=high) {
        int mid = (low+high)/2;
        if(nums[mid]==target) {
            ans=mid;
            low=mid+1;
        } else if (nums[mid]<target) {
            low=mid+1;
        } else {
            high=mid-1;
        }
    }
    res.push_back(ans);
    return res;
}