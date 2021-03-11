vector<int> levelOrder(Node* root)
{
    vector<int> res;
    if(root == NULL) return res;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        res.push_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return res;
}