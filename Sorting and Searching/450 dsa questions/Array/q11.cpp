// https://leetcode.com/problems/find-the-duplicate-number/


#include<bits/stdc++.h>
using namespace std;


// Approach 1: use two nested loops and check if an element is being repeated. (TC-O(n^2) SC-O(1))

// Approach 2: sort the array and check if an element is being repeated in a single loop. (TC-O(nlogn) SC-O(1) with array modification)

// Approach 3: using hashing in a loop check if an element is appearing again.  (TC-O(n) SC-O(n))
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(int i=0; i<nums.size(); i++) {
            if(m[nums[i]]) return nums[i];
            else {
                m[nums[i]]=true;
            }
        }
        return 0;
    }
};

// Approach 4: using binary search, low = 1, high = n; if (count of elements <= mid) == mid ? low = mid+1 : high = mid.  (TC-O(nlogn) SC-O(1) withot array modification)
// https://leetcode.com/problems/find-the-duplicate-number/discuss/73045/Simple-C%2B%2B-code-with-O(1)-space-and-O(nlogn)-time-complexity

// Approach 5: cosidering the array as linked list and finding a loop using floyd slow fast cycle detection problem. (TC-O(n) SC-O(1))
// https://leetcode.com/problems/find-the-duplicate-number/discuss/72846/My-easy-understood-solution-with-O(n)-time-and-O(1)-space-without-modifying-the-array.-With-clear-explanation.