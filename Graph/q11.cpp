// First approach : Got TLE
class Graph {

	public:
	    unordered_map <string, vector<string>> adj;
    
		void addEdge (string x, string y) {

			// Considering undirectional graph
            adj[x].push_back(y);
			adj[y].push_back(x);
		}
    
    
        int bfs (string source, string des) {
        	queue<pair <string, int>> q;
        	unordered_map<string, bool> visited;
	        q.push({source, 1});
	        visited[source] = true;
	        while (!q.empty()) {
		        auto temp = q.front();
                if (temp.first == des) return temp.second;
        		q.pop();
		        for (auto ele : adj[temp.first]) {
        			if (!visited[ele]) {
	        			q.push({ele, temp.second+1});
				        visited[ele] = true;
        			}
		        }
	        }
	        return 0;
        }
};


class Solution {
public:
    
    bool possible (string a, string b) {
        int c=0;
        for (int i=0; i<a.size(); i++) {
            if (a[i]!=b[i]) c++;
        }
        return c==1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        Graph g;
        
        bool flag = false;
        for (int i=0; i<wordList.size(); i++) {     // this is going n^2
            for (int j=0; j<wordList.size(); j++) {
                if (possible(wordList[i], wordList[j])) 
                    g.addEdge(wordList[i], wordList[j]);
            }
            if (wordList[i] == beginWord) flag = true;
        }
        if (!flag) {
            for (int j=0; j<wordList.size(); j++) {
                if (possible(beginWord, wordList[j])) 
                    g.addEdge(beginWord, wordList[j]);
            }
        }
        return g.bfs(beginWord, endWord);
    }

    // OPTIMIZED VERSION
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        Graph g;
        unordered_set<string> exist (wordList.begin(), wordList.end());
        bool flag = false;
        
        for (int i=0; i<wordList.size(); i++) {
            for (int j=0; j<wordList[i].size(); j++) {
                string s = wordList[i];
                for (int k = 0; k<26; k++) {
                    s[j] = 'a' + k;
                    if (exist.find(s) != exist.end()) {
                        g.addEdge(wordList[i], s);
                    }
                }
            }
            
            if (wordList[i] == beginWord) flag = true;
        }
        if (!flag) {
            for (int j=0; j<beginWord.size(); j++) {
                string s = beginWord;
                for (int k = 0; k<26; k++) {
                    s[j] = 'a' + k;
                    if (exist.find(s) != exist.end()) {
                        g.addEdge(beginWord, s);
                    }
                }
            }
        }
        return g.bfs(beginWord, endWord);
        
    }
};


// Concise and efficient code : https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};


/// SHORT CODE WITHOUT CREATING A GRAPH::
int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> exist (wordList.begin(), wordList.end());
    
    queue<pair <string, int>> q;
    unordered_map<string, bool> visited;
    q.push({beginWord, 1});
    visited[beginWord] = true;
    while (!q.empty()) {
        auto temp = q.front();
        if (temp.first == endWord) return temp.second;
        q.pop();
        for (int i=0; i<temp.first.size(); i++) {
            string s = temp.first;
            for (int k = 0; k<26; k++) {
                s[i] = 'a' + k;
                if (exist.find(s) != exist.end() && !visited[s]) {
                    q.push({s, temp.second+1});
                    visited[s] = true;
                }
            }
        }
    }
        
    return 0;
}