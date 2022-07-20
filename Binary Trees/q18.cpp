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

// maintain the head and tail of linked list and add the current node after tail according to inorder

// keep a prev element node and update left of cur with prev
// linearly traverse the dll in reverse using prev and update the next pointer