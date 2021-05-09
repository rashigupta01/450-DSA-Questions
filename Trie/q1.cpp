
// I implemented reccursively
// On gfg iterative version is used : https://www.geeksforgeeks.org/trie-insert-and-search/

struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    if (key.empty() || key.size()==0) {
        root->isLeaf = true;
        return;
    }
    int first_char = CHAR_TO_INDEX(key[0]);
    if (root->children[first_char] == NULL) {
        root->children[first_char] = getNode();
    }
    key.erase(key.begin(), key.begin()+1);
    insert (root->children[first_char], key);
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    if (key.empty() || key.size()==0) {
        return root->isLeaf;
    }
    int first_char = CHAR_TO_INDEX(key[0]);
    if (root->children[first_char] != NULL) {
        key.erase(key.begin(), key.begin()+1);
        return search (root->children[first_char], key);
    } else {
        return false;
    }
}