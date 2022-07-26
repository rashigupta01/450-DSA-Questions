// Since we can't use any data structure we will use reccursion stack to hold the elements
// Function defination :
// Base condition- if stack is empty do nothing 
// store the top element, pop it, then reverse the rest stack 
// now we need to insert the stored element at the end of the stack (refer q13)

// Time complexity O(n^2)

// storing in a vector
class Solution{
public:
    void util (stack<int> st, vector<int> &res) {
        if (st.empty()) return;
        res.push_back(st.top());
        st.pop();
        util (st, res);
    }
    vector<int> Reverse(stack<int> st){
        vector<int> res;
        util (st, res);
        return res;
    }
};