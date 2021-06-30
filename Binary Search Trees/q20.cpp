bool isDeadEndUtil(Node *root, int low = 0, int high = INT_MAX)
{
    if (root == NULL) return false;
    if (root->data == high-1 && root->data == low+1) return true;
    
    return isDeadEndUtil(root->left, low, root->data) || isDeadEndUtil(root->right, root->data, high);
}
bool isDeadEnd (Node* root) {
    return isDeadEndUtil (root);
}