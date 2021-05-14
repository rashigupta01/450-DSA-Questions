// if we are allowed to modify the linked list
// Approach: reverse both the numbers, simply add then reverse the final result
Node* reverse (Node* head) {
    Node* prev=NULL, *curr=head;
    while (curr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first = reverse (first);
    second = reverse (second);
    
    Node* result=NULL, *tail = NULL;
    int carry = 0;
    while (first || second) {
        int sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
        if (result==NULL) {
            result = new Node (sum%10);
            tail = result;
        } else {
            tail->next = new Node (sum%10);
            tail = tail->next;
        }
        carry = sum/10;
        if (first) first = first->next;
        if (second) second = second->next;
    }
    if (carry) {
        tail->next = new Node (carry);
    }
    return reverse (result);
}

// if modification is not permitted: https://www.geeksforgeeks.org/sum-of-two-linked-lists/
// use reccursion or stack
// find the difference in sizes of both linked lists
// move the larger one ahead by diff
// find sum using reccursion and then add the left over nodes with carry
