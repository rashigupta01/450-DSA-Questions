int helper (Node* node) {
    if(node == NULL) return 0;
    
    int left = helper(node->left);
    int right = helper(node->right);
    int temp = node->data;
    node->data = left + right;
    return temp+node->data;
}
void toSumTree(Node *node)
{
    helper(node);
}
