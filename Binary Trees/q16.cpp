class Solution {
public:
    void findleafnodes (Node* root, vector<int> &res) {
        if (root==NULL) return;
        
        if (root->left || root->right) {
            findleafnodes(root->left, res);
            findleafnodes(root->right, res);
            return;
        }
        res.push_back(root->data);
    }
    
    void findleftboundary (Node* root, vector<int> &res) {
        while (root) {
            if (root->left) {
                res.push_back(root->data);
                root = root->left;
            }  else if (root->right) {
                res.push_back(root->data);
                root = root->right;
            } else {
                root = NULL;
            }
        }
    }

    void findrightboundary (Node* root, vector<int> &res) {
        stack<int> s;
        while (root) {
            if (root->right) {
                s.push(root->data);
                root = root->right;
            }  else if (root->left) {
                s.push(root->data);
                root = root->left;
            } else {
                root = NULL;
            }
        }
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        
        res.push_back(root->data);
        findleftboundary (root->left, res);
        findleafnodes(root->left, res);
        findleafnodes(root->right, res);
        findrightboundary (root->right, res);
        
        return res;
    }
};