bool isDeadEndUtil(Node *root, int low = 0, int high = INT_MAX)
{
    if (root == NULL) return false;
    if (root->data == high-1 && root->data == low+1) return true;
    
    return isDeadEndUtil(root->left, low, root->data) || isDeadEndUtil(root->right, root->data, high);
}
bool isDeadEnd (Node* root) {
    return isDeadEndUtil (root);
}


// Iterative approach
// we need to check if there is a leaf node with value x such that x+1 and x-1 exist in BST (exception of x = 1)
//   traverse the whole BST and store all nodes in a set
//   store all leaves in a separate hash
//   check for every leaf node x, if x-1 and x+1 are present in set or not.