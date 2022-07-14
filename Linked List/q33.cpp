// my reccursive approach
Node *compute(Node *head)
{
    if (head==NULL || head->next==NULL) return head;
    head->next = compute(head->next);
    if (head->data < head->next->data) {
        Node* next = head->next;
        delete head;
        return next;
    } else {
        return head;
    }
}