// Two liner
int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// This is top down approach
class Solution {
public:
    int maxDepthHelper(TreeNode* root, int height) {
        if(root == NULL) return height;
        int h1 = maxDepthHelper(root->left, height+1);
        int h2 = maxDepthHelper(root->right, height+1);
        return max(h1, h2);
    }
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root, 0);
    }
};

// This is bottom up approach
class Solution {
public:
    int maxDepthHelper(TreeNode* root) {
        if(root == NULL) return 0;
        int h1 = maxDepthHelper(root->left);
        int h2 = maxDepthHelper(root->right1);
        return max(h1, h2) + 1;
    }
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root);
    }
};