
// My solution : not efficient, generating duplicates ans storing in a set
class Solution {
public:
    unordered_set<string> result;
    
    void util (string s, int d_o, int d_c, int pos, string ans, int net_open) {
        if (pos == s.size()) {
            if (d_o || d_c) return;
            else result.insert(ans);
            return;
        }
        
        if (s[pos] == '(') {
            if (d_o) {
                util (s, d_o-1, d_c, pos+1, ans, net_open);
            }
            util (s, d_o, d_c, pos+1, ans+'(', net_open+1);
        } else if (s[pos] == ')') {
            if (d_c) {
                util (s, d_o, d_c-1, pos+1, ans, net_open);
            }
            if (net_open)
                util (s, d_o, d_c, pos+1, ans+')', net_open-1);
        } else {
            util (s, d_o, d_c, pos+1, ans + s[pos], net_open);
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int delete_open = 0, delete_close = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') {
                delete_open++;
            } else if (s[i]==')') {
                if (delete_open == 0) {
                    delete_close++;
                } else {
                    delete_open--;
                }
            }
        }
        
        util (s, delete_open, delete_close, 0, "", 0);
        vector<string> answer;
        for (auto str : result) answer.push_back(str);
        return answer;
    }
};

// Efficient approach: must visit, important
// https://leetcode.com/problems/remove-invalid-parentheses/discuss/75027/Easy-Short-Concise-and-Fast-Java-DFS-3-ms-solution

// Iterative approach : BFS : concise, simple and easy to understand
// https://www.geeksforgeeks.org/remove-invalid-parentheses/