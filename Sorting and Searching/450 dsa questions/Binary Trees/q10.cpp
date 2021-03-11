// Reccursive approach: https://www.geeksforgeeks.org/print-right-view-binary-tree/
// keep track of the max level and if the current element is more than the max level reached print it and increase the max level
// NOTE: In this we have to reccurse for right child first then the left child

// Iterative approach: https://www.geeksforgeeks.org/iterative-postorder-traversal/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return vector<int>();
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levcount = q.size();
            res.push_back(q.back()->val);
            for (int i=0; i<levcount; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        
        return res;
    }
};