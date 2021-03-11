// Do checkout Morris traversal https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/


#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int val;
        node *left, *right;
        node(int data) {
            val=data;
            left=NULL;
            right = NULL;
        }
};

// Approach 1: Using a visited map 
void inorder2 (node* root) {

    if(root==NULL) {
        cout<<"Empty tree";
        return;
    }
    unordered_map<node*, bool> visited;
    stack<node*> s;
    s.push(root);
    visited[root] = true;

    while(!s.empty()) {
        node* temp = s.top();
        if(temp->left==NULL || visited[temp->left]) {
            s.pop();
            cout<<temp->val<<" ";
            if(temp->right) {
                visited[temp->left] = true;
                s.push(temp->right);
            }
        } else {
            visited[temp->left] = true;
            s.push(temp->left);
        }
    }
}

// Approach 2: without using a visited map
void inorder (node* root) {
    
    stack<node*> s;
    node* curr = root;
    while(curr || !s.empty()) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        node* temp = s.top();
        s.pop();
        cout<<temp->val<<" ";
        curr = temp->right;
    }
}

// Do checkout Morris traversal https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

int main() {
    struct node *root = new node(1);
    root->left        = new node(2);
    root->right       = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);
    inorder(root);
}