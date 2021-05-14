// Approach 1 : 
// find inorder then return kth element

// A better approach: stop when found kth element, no need to traverse more
class Solution
{
    public:
    int util (Node* root, int K, int &pos) {
        if (!root) return -1;
        
        int isright = util (root->right, K, pos);
        if (isright != -1) return isright;
        pos++;
        if (pos==K) return root->data;
        return util (root->left, K, pos);
    }
    int kthLargest(Node *root, int K)
    {
        int pos = 0;
        return util (root, K, pos);
    }
};