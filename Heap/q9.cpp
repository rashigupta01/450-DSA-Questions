// Backtracking approach : exponential time complexity
class Solution {
public:
    unordered_set<string> checked;
    string util (string s, string curr, vector<bool> &taken) {
        if (curr.size() == s.size()) {
            return curr;
        }
        if (checked.find(curr) != checked.end()) return "";
        for (int i=0; i<s.size(); i++) {
            if (curr.empty() || (curr[curr.size()-1] != s[i] && !taken[i])) {
                taken[i] = true;
                string maybe = util (s, curr+s[i], taken);
                if (maybe != "") return maybe;
                taken[i] = false;
            }
        }
        checked.insert(curr);
        return "";
    }
    string reorganizeString(string s) {
        vector<bool> taken (s.size(), false);
        return util (s, "", taken);
    }
};

// Heaps approach : O(NlogN)
class Solution {
public:
    string rearrangeString(string s)
    {
        vector<int> counter (26, 0);
        for (int i=0; i<s.size(); i++) {
            counter[s[i]-'a']++;
        }
        
        priority_queue <pair<int, int>> pq;
        for (int i=0; i<26; i++) {
            if (counter[i]) {
                pq.push ({counter[i], i});
            }
        }
        if (pq.top().first > (s.size()+1)/2) return "-1";
        
        int lastletter = -1;
        string ans (s.size(), 'a');
        int pos = 0;
        while (pq.size()>0) {
            auto letter = pq.top();
            pq.pop();
            
            while (letter.first--) {
                if (pos >= s.size()) pos = 1;
                ans[pos] = 'a' + letter.second;
                pos+=2;
            }        
        }
        return ans;
    }
};

// Most efficient : O(n) - https://leetcode.com/problems/reorganize-string/discuss/232469/Java-No-Sort-O(N)-0ms-beat-100
// first fill even indices then odd indices, first with letter with max freq then with rest elements