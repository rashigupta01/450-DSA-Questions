// O(n*n) approach
int AlternatingaMaxLength(vector<int>&nums){
    vector<int> lmax(nums.size());
    vector<int> lmin(nums.size());
    int res=0, n = nums.size();
    for (int i=0; i<n; i++) {
        lmax[i] = lmin[i] = 1;
        for (int j=0; j<i; j++) {
            if (nums[j] < nums[i]) {
                lmax[i] = max (lmax[i], lmin[j]+1);
            } else if (nums[j]>nums[i]) {
                lmin[i] = max (lmin[i], lmax[j]+1);
            }
        }
        res = max (res, max(lmin[i], lmax[i]));
    }
    return res;
}

// O(n) approach
int AlternatingaMaxLength(vector<int>&arr){
        		     
    int n = arr.size();
    int inc = 1;
    int dec = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            inc = dec + 1;
        }
        else if (arr[i] < arr[i - 1]) {
            dec = inc + 1;
        }
    }
    return max(inc, dec);
}