Node * bToDLL(Node *root)
{
    if (root == NULL) return NULL;
    
    Node* left = bToDLL (root->left);
    Node* right = bToDLL (root->right);
    
    root->right = right;
    if (right!=NULL) {
        right->left = root;
    }
    
    if (left != NULL) {
        Node* temp = left;
        while(temp->right!=NULL) {
            temp = temp->right;
        }
    
        temp->right = root;
        root->left = temp;
        root = left;
        
    } else root->left = NULL;
    return root;
}