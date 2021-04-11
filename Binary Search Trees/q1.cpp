Node* insert(Node* root, int key)
{
    if (!root) {
        Node* newnode = new Node(key); 
        return newnode;
    }
    if (root->data == key) return root;
    else if (root->data > key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert (root->right, key);
    }
    return root;
}