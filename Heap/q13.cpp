// Wrong approach: using reccursion check if left and right child is less than root or not
// Problem in this approach: this approach do not check for completeness (heap is always complete)
// Note: Pass index of calculated with formula and check 

// Correct approach : using queue (BFS)
bool isHeap(struct Node * tree)
{
    queue<Node*> q;
    q.push(tree);
    bool iscomplete=false;
    while (!q.empty()) {
        auto ele = q.front();
        q.pop();
        if (iscomplete) {
            if (ele->left || ele->right) return false;
        } else {
            if (!ele->right) iscomplete = true;
            else {
                if (!left) return false;
            }
        }
        
        if (ele->left) {
            if (ele->left->data > ele->data) return false;
            q.push(ele->left);                
        }
        
        if (ele->right) {
            if (ele->right->data > ele->data) return false; 
            q.push(ele->right);
        }
    }
    return true;
}

// Simplified code of my approach on gfg : https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-heap/
bool isHeap(Node* root)
{
    // Your code here
    queue<Node*> q;
    q.push(root);
    bool nullish = false;
    while (!q.empty()) 
    {
        Node* temp = q.front();
        q.pop();
        if (temp->left) 
        {
            if (nullish 
                || temp->left->data 
                >= temp->data) 
            {
                return false;
            }
            q.push(temp->left);
        }
        else {
            nullish = true;
        }
        if (temp->right)
        {
            if (nullish
                || temp->right->data
                >= temp->data) 
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            nullish = true;
        }
    }
    return true;
}