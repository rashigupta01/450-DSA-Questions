// couldn't solve

// https://www.geeksforgeeks.org/check-binary-tree-contains-duplicate-subtrees-size-2/
// my code, referred logic from editorial
bool check;
unordered_set<string> exist;

string util (Node *root) {
    if (!root) return "$";
    
    string l = util (root->left);
    string r = util (root->right);
    
    string cur = to_string (root->data) + l + r;
    if (cur.size() > 3 && exist.find(cur)!=exist.end()) check = true;
    
    exist.insert(cur);
    return cur;
}

bool dupSub(Node *root)
{
    exist.clear();
    check = false;
    util (root);
    return check;
}