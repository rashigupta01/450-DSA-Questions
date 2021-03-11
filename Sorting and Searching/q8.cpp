// Approach 1: Check count of each element using two loops. (TC-O(n^2) SC-O(1))

// Approach 2: Sort the array and find in a single loop. (TC-O(nlogn) SC-O(1))

// Approach 3: Use hashing. Find the required element in a single loop. (TC-O(n) SC-O(n))

// **Approach 4: Boyer Moore’s Voting Algorithm
// increase conter if cur element == majority element else decrease the counter
// if counter is 0 make the current element as majority element and increase the counter
// Key: Different elements nullify each other
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0, majority;
        for(int i=0; i<nums.size(); i++) {
            if(counter==0) {
                majority=nums[i];
                counter=1;
            } else if(nums[i]==majority) counter++;
            else counter--;
        }
        return majority;
    }
};