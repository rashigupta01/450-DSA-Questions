// Approach 1 : 
// find inorder then return kth element

// A better approach: stop when found kth element, no need to traverse more
class Solution{
  public:
    int util (Node* root, int K, int &pos) {
        if (!root) return -1;
        
        int isleft = util (root->left, K, pos);
        if (isleft != -1) return isleft;
        pos++;
        if (pos==K) return root->data;
        return util (root->right, K, pos);
    }
    // Return the Kth smallest element in the given BST 
    int KthSmallestElement(Node *root, int K)
    {
        int pos = 0;
        return util (root, K, pos);
    }
};