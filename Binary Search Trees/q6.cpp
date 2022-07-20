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

// O(1) space by maintaining a previous node in inorder and asigning current node(root) to next of prev
void inorder (Node* root, Node** prev) {
    if (!root) return;
    inorder (root->left, prev);
    if (*prev) {
        (*prev)->next = root;
    }
    *prev = root;
    inorder (root->right, prev);
}

void populateNext(struct Node* p) {
    if (!p) return;
    Node* prev = NULL;
    inorder(p, &prev);
}