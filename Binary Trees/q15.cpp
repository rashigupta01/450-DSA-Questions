// DFS approach
unordered_map <int, vector<int>> m;
int level;

void util (Node* root, int lvl) {
    if (root==NULL) return;
    m[lvl].push_back(root->data);
    level = max(level, lvl);
    util (root->left, lvl+1);
    util (root->right, lvl);
}

vector<int> diagonal(Node *root)
{
    level = 0;
    m.clear();
    util (root, 0);
    
    vector<int> res;
    for (int i=0; i<=level; i++) {
        for (int ele : m[i]) {
            res.push_back(ele);
        }
    }
    return res;
}