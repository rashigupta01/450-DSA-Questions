class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        unordered_map <int, Node*> visited;
        Node* clone = new Node(node->val);
        visited[node->val] = clone;
        util(node, clone, visited);
        return clone;
    }
    
    void util (Node* node, Node* clone, unordered_map<int, Node*>& visited) {
        
        for (auto ele : node->neighbors) {
            
            if (visited.find(ele->val) == visited.end()) {
                Node* temp = new Node(ele->val);
                visited[ele->val] = temp;
                clone->neighbors.push_back(temp);
                util (ele, temp, visited);
            } else {
                clone->neighbors.push_back(visited[ele->val]);
            }
        }
        cout<<endl;
    }
};

// 9 liner : https://leetcode.com/problems/clone-graph/discuss/42313/C%2B%2B-BFSDFS
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};