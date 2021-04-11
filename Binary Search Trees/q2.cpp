class Solution {
public:
    int util (TreeNode* root) {
        TreeNode* minele = root;
        while (minele->left) {
            minele = minele->left;
        }
        return minele->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==nullptr) return root;
        
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                root = nullptr;
            } else if (!root->left) {
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            } else if (!root->right) {
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            } else {
                int minele = util (root->right);
                root = deleteNode (root, minele);
                root->val = minele;
            }
        } else if(root->val > key) {
            root->left = deleteNode (root->left, key);
        } else {
            root->right = deleteNode (root->right, key);
        }
        
        return root;
    }
};