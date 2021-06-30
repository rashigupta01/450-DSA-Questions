// find the inorder traversal of the array representation of the binary tree
// find the min swaps to convert it into sorted array (as inorder traversal of bst is increasing order)

// for the last step the ques is same as Sorting and searching q18
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<int> aux (nums.begin(), nums.end());
	    sort (aux.begin(), aux.end());
	    
	    unordered_map<int, int> idx;
	    for (int i=0; i<nums.size(); i++) {
	        idx[nums[i]] = i;
	    }
	    
	    int c=0;
	    for (int i=0; i<nums.size(); i++) {
	        if (nums[i]==aux[i]) continue;
	        
	        int swapwith = idx[aux[i]];
	        swap(nums[i], nums[swapwith]);
	        idx[nums[swapwith]] = swapwith;
	        idx[nums[i]] = i;
	        c++;
	        
	    }
	    return c;
	}
};