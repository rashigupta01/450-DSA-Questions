// Editorial : https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
// Refer editorial for code of approaches mentioned below

// Approach 1 : O(nlogn) 
// if left and right subtree are bst then check if root is greater than the max val in left subtree and less than the min value in right subtree 
class Solution
{
    public:
    bool isBST(Node* root) 
    {
        if (!root) return true;
        if (!isBST(root->left)) return false;
        if (!isBST(root->right)) return false;
        
        if (root->left) {
            Node* temp = root->left;
            while (temp->right) temp = temp->right;
            if (root->data <= temp->data) return false;
        }
        
        if (root->right) {
            Node* temp = root->right;
            while (temp->left) temp = temp->left;
            if (root->data >= temp->data) return false;
        }
        return true;
    }
};

// Approach 2 : O(n)
/*write a utility helper function isBSTUtil(struct node* node, int min, int max) keeping track of the narrowing min and max 
 looking at each node only once. Initial values for min and max : INT_MIN and INT_MAX — they narrow from there. 
 While recursing for left subtree reduce max to node->data-1 and for right subtree increase min to node->data+1

 The idea is that elements to left should be less than the root and elements to the right should be greater than the node 
*/

// Approach 2 : O(n)
/*idea is to find inorder traversal and check if it is stricktly increasing or not. We would need auxiliary array for this

 space can be optimized by maintaining a previous element in inorder traversal and check if current node is more than previous element or not.
*/