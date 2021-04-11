// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1

class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        vector<int> ans(2, 0);
        int netxor = 0;
        for(int i=0; i<nums.size(); i++) {
            netxor ^= nums[i];
        }
        int mask = netxor&(-netxor);
        for(int i=0; i<nums.size(); i++) {
            ans[(nums[i]&mask)!=0] ^= nums[i];
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};