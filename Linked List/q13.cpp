Node* merge (Node* h1, Node* h2) {
    Node *head=NULL, *tail=NULL;
    while (h1 && h2) {
        Node* toadd;
        if (h1->data < h2->data) {
            toadd = h1;
            h1 = h1->next;
        } else {
            toadd = h2;
            h2 = h2->next;
        }

        if (!head) {
            head = toadd;
            tail = toadd;
        } else {
            tail->next = toadd;
            tail = tail->next;
        }
    }
    if (h1) {
        tail -> next = h1;
    } else {
        tail->next = h2;
    }
    return head;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    
    Node *fast=head, *slow=head, *prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast) {
        prev = slow;
        slow = slow->next;
    }
    prev->next = NULL;

    Node* h1 = mergeSort (head);
    Node* h2 = mergeSort (slow);
    head = merge (h1, h2);

    return head;
}