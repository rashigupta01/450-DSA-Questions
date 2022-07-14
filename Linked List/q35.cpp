// Using length of linked list
int getNthFromLast(Node *head, int n)
{
    int count = 0; 
    Node* temp = head;
    while (temp) {
        count ++;
        temp = temp->next;
    }
    
    int pos = count - n;
    if (pos<0) return -1;
    
    Node* res = head;
    while (pos--) {
        res = res->next;
    }
    
    return res->data;
}

// Method 2: two pointers
/*
Maintain two pointers. Initialize both pointers to head. First, move the reference pointer to n nodes from head. 
Now move both pointers one by one until the reference pointer reaches the end. Now the main pointer will point to 
nth node from the end. Return the main pointer.
*/