void inorder (node* root, queue<node*> &q) {
    if (!root) return;
    inorder (root->left, q);
    q.push(root);
    inorder (root->right, q);
}

void populateNext(struct node* p) {
    if (!p) return;
    queue<node*> q;
    inorder(p, q);
    while (q.size() > 1) {
        node* cur = q.front();
        q.pop();
        cur->next = q.front();
    }
}

// Queue can be avoided by using reverse inorder traversal and keeping a previous node and keep assigning it as successor