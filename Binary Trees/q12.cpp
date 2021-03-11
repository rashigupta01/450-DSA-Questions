// https://www.geeksforgeeks.org/bottom-view-binary-tree/

vector <int> bottomView(Node *root)
{
    unordered_map<int, int> m;
    int mleft=0, mright=-1;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        m[temp.second] = temp.first->data;
        mleft = min(mleft, temp.second);
        mright = max(mright, temp.second);
        
        if (temp.first->left)
            q.push({temp.first->left, temp.second-1});
        if (temp.first->right)
            q.push({temp.first->right, temp.second+1});
    }
    
    vector<int> res;
    for (int i=mleft; i<=mright; i++) {
        res.push_back(m[i]);
    }
    return res;
}


// Reccursive approach: Maintain two variables one for depth and one for horizontal distance.
// If current hd is recieved before also compare their depth and update accordingly
