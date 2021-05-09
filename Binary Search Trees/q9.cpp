// Time complexity : O(nlogn)
// Space complexity : O(n)
Node* createbst (Node* root, vector<int> &inorder, int &pos) {
    if (root==NULL) return NULL;
    Node* newroot = new Node (0);
    newroot->left = createbst (root->left, inorder, pos);
    newroot->data = inorder[pos++];
    newroot->right = createbst (root->right, inorder, pos);
    return newroot;
}

void traversal (Node* root, vector<int> &inorder) {
    if (root==NULL) return;
    traversal (root->left, inorder);
    inorder.push_back(root->data);
    traversal (root->right, inorder);
}

Node *binaryTreeToBST (Node *root)
{
    vector<int> inorder;
    traversal (root, inorder);
    sort (inorder.begin(), inorder.end());
    int pos=0;
    return createbst (root, inorder, pos);
}