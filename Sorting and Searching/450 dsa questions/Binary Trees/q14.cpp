// TC-O(n^2) Top Down
int height(TreeNode* root) {
    if (root==NULL) return 0;
    
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(TreeNode* root) {
    
    if (root== NULL) return true;
    
    int left = height(root->left);
    int right = height(root->right);
    
    if (abs(left-right)>1) return false;
    
    return isBalanced(root->left) & isBalanced(root->right);
        
}

// TC-O(n) Bottom Up
// https://leetcode.com/problems/balanced-binary-tree/discuss/35691/The-bottom-up-O(N)-solution-would-be-better
int dfsHeight (TreeNode *root) {
    if (root == NULL) return 0;
    
    int leftHeight = dfsHeight (root -> left);
    if (leftHeight == -1) return -1;
    int rightHeight = dfsHeight (root -> right);
    if (rightHeight == -1) return -1;
    
    if (abs(leftHeight - rightHeight) > 1)  return -1;
    return max (leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode *root) {
    return dfsHeight (root) != -1;
}