// Approach : just swap the pointers of next and prev of each node

// Iterative version
// A bit different to given on gfg: https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/
Node* reverseDLL(Node * head)
{
    Node *cur = head, *prev = NULL, *next;
    while (cur) {
        next = cur->next;
        cur->next = cur->prev;
        cur->prev = next;
        prev = cur;
        cur = next;
    }
    return prev;
}

// Try its reccursive version