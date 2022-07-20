// https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/

vector<int> topView(struct Node *root)
{
    unordered_map<int, int> m;
    int mleft=0, mright=-1;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        if (m[temp.second] == 0) {
            m[temp.second] = temp.first->data;
            mleft = min(mleft, temp.second);
            mright = max(mright, temp.second);
        }
        
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

//Reccursive approach: Maintain two variables one for depth and one for horizontal distance.
// If current hd is recieved before also compare their depth and update accordingly


// Efficient approach: *No hash map used* 
// Keep a stack for nodes to the left of root and will be there in top view
// Keep a vector for nodes to the right of root and wil be their in top view
// Using a level order traversal if the current node's hd is less than maxLeft push it in the stack
// and if it is more than maxright push_back it in the vector