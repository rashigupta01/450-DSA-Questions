// iterating right before left just to get the vector in the order it is expected
// no other reason i have...
// Approach : converting tree into string and then checking its existance in map
string util (Node* root, vector<Node*> &res, unordered_map<string, int> &m) {
    if (!root) return "";
    
    string cur = "(" + util (root->right, res, m) +"," + to_string(root->data) + "," + util (root->left, res, m) + ")";
    m[cur]++;
    if (m[cur]==2) res.push_back(root);
    return cur;
}
vector<Node*> printAllDups(Node* root)
{
    unordered_map<string, int> m;
    vector<Node*> res;
    util (root, res, m);
    return res;
}