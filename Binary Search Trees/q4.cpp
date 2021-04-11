// BRUTE FORCE APPROACH: First i found inorder traversal and then pre = previous in queue, suc = next in queue--------------------
// NOTE : This approach do not use the fact that given tree is bst
// TC - O(n)
void inorder (Node* root, queue<Node*>& q) {
    if (!root) return;
    inorder (root->left, q);
    q.push(root);
    inorder (root->right, q);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    
    queue<Node*> q;
    inorder (root, q);
    bool flag = false;
    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();
        
        if (cur->key >= key) {
            suc = cur;
            flag = true;
            break;
        }
        pre = cur;
    }
    if (flag) {
        if (suc->key==key) {
            if (q.empty()) suc = NULL;
            else suc = q.front();
        }
    }
}

// OPTIMIZED APPROACH : if root < key, that means all the nodes in the left subtree would be less than root (and key) 
// so they can't contribute in pre or suc. Similarly if root > key, right subtree is of no use.
// TC - O(logn)
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (!root) return;
    
    if (root->key == key) {
        if (root->left) {
            Node* temp = root->left;
            while (temp->right) temp = temp->right;
            pre = temp;
        }
        if (root->right) {
            Node* temp = root->right;
            while (temp->left) temp = temp->left;
            suc = temp;
        }
    }
    
    else if (root->key < key) {
        pre = root;
        findPreSuc (root->right, pre, suc, key);
    }
    
    else {
        suc = root;
        findPreSuc (root->left, pre, suc, key);
    }
}