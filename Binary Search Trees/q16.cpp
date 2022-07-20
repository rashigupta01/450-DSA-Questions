int count = 0;
void util (Node* root, int l, int h) {
    if (root == NULL) return;
    if (root->data <= h && root->data >= l) {
        count ++;
        util (root->left, l, h);
        util (root->right, l, h);
    }
    else if (root->data < l) {
        util (root->right, l, h);
    }
    else if (root->data > h) {
        util (root->left, l, h);
    }
}

int getCount(Node *root, int l, int h)
{
    util (root, l, h);
    return count;
}