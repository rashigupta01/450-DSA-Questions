Node* deleteNode(Node* head, int key)  {
      
    if (*head == NULL)
        return;
      
    Node *cur = head, *prev = NULL;
    while (cur->data != key && cur->next!=head) {
        prev = cur;
        cur = cur->next;
    }
    if (cur->data == key) {
        if (head->next == head) {
            delete head;
            return NULL;
        }
        if (cur == head) {
            prev = head;
            while (prev->next!=head) prev = prev->next;
            head = head->next;
        }
        prev->next = cur->next;
        delete cur;
    }
    return head;
} 