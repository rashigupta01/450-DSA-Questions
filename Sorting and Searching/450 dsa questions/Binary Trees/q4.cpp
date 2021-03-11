/*
Refrences:
    https://www.geeksforgeeks.org/diameter-of-a-binary-tree/
    https://www.geeksforgeeks.org/diameter-tree-using-dfs/
    https://www.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/
*/


// My approach (TC - O(n^2))        given in first link
int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    
    int left = maxDepth(root->left);
    int right = maxDepth (root ->right);
    int res = left + right;
    res = max (res, diameterOfBinaryTree(root->left));
    res = max (res, diameterOfBinaryTree(root->right));
    return res;
}
int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Efficient approach :  given in third link 
// https://leetcode.com/problems/diameter-of-binary-tree/discuss/101132/Java-Solution-MaxDepth
public class Solution {
    int max = 0;
    
    public int diameterOfBinaryTree(TreeNode root) {
        maxDepth(root);
        return max;
    }
    
    private int maxDepth(TreeNode root) {
        if (root == null) return 0;
        
        int left = maxDepth(root.left);
        int right = maxDepth(root.right);
        
        max = Math.max(max, left + right);
        
        return Math.max(left, right) + 1;
    }
}

// DFS approach     : given in second link
// start DFS from a root and find farthest node from it. Now we start DFS from this node and the farthest node from it, will give the diameter of the tree. 
