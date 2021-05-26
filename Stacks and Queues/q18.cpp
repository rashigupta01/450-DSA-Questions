// My approach: very complex, time and space complexity is also not good. do check other approaches below 
// used the concept of merge overlapping intervals
class Solution {
public:
    void insert (stack<pair<int, int>> &s, int open, int close) {
        if (s.empty()) {
            s.push({open, close});
            return;
        }
        auto last = s.top();
        if (last.first>open) {
            s.pop();
        }
        if (s.empty()) {
            s.push({open, close});
            return;
        }
        last = s.top();
        while (!s.empty() && last.second == open-1) {
            open = last.first;
            last = s.top();
            s.pop();
        }
        s.push({open, close});
    }
    
    int longestValidParentheses(string s) {
        stack <int> st;
        stack <pair<int, int>> paren;
        int res = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]=='(') {
                st.push(i);
            } else if (s[i]==')' && !st.empty()) {
                int last = st.top();
                st.pop();
                insert(paren, last, i);
            }
        }
        while (paren.size()>0) {
            res = max (res, paren.top().second - paren.top().first + 1);
            paren.pop();
        }
        return res;
    }
};

// Following approaches are mentioned here : https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
// Check out the link for better understanding (if have time), everything is mentioned there.


//* O(n^2) check for each substring

//* O(n) The idea is to store indexes of previous starting brackets in a stack. The first element of the stack is a 
// special element that provides index before the beginning of valid substring. follow the steps below
// 1) Create an empty stack and push -1 to it. 
//    The first element of the stack is used 
//    to provide a base for the next valid string. 

// 2) Initialize result as 0.

// 3) If the character is '(', push index 'i' to the stack. 
   
// 4) Else (if the character is ')')
//    a) Pop an item from the stack
//    b) If the stack is not empty, then find the
//       length of current valid substring by taking 
//       the difference between the current index and
//       top of the stack. If current length is more 
//       than the result, then update the result.
//    c) If the stack is empty, push the current index
//       as a base for the next valid substring.

// 5) Return result.
// Refer the link for code


//* O(n) : DP approach - The idea is to maintain an array that stores the length of the longest valid substring ending
//           at that index. We iterate through the array and return the maximum value. Follow the steps below
// 1) Create an array longest of length n initialized to zero.
//    The array will store the length of the longest valid 
//    substring ending at that index.

// 2) Initialize result as 0.

// 3) Iterate through the string from second character
//    a) If the character is '(' set longest[i]=0 as no 
//       valid sub-string will end with '('.
//    b) Else
//       i) if s[i-1] = '('
//             set longest[i] = longest[i-2] + 2
//       ii) else
//             set longest[i] = longest[i-1] + 2 + 
//             longest[i-longest[i-1]-2]

// 4) In each iteration update result as the maximum of 
//    result and longest[i]

// 5) Return result.
 

//* O(1) space : use counter for open and close brackets 

// 1) The idea to solve this problem is to traverse the string on and keep track of the count of open parentheses 
//  and close parentheses with the help of two counters left and right respectively.

// 2) First, the string is traversed from the left towards the right and for every “(” encountered, the left counter is 
//  incremented by 1 and for every “)” the right counter is incremented by 1.

// 3) Whenever the left becomes equal to right, the length of the current valid string is calculated and if it greater 
//   than the current longest substring, then value of required longest substring is updated with current string length.

// 4) If the right counter becomes greater than the left counter, then the set of parentheses has become invalid and hence
//   the left and right counters are set to 0.

// 5) After the above process, the string is similarly traversed from right to left and similar procedure is applied.