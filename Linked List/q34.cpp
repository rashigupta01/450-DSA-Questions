// 1. Maintain two linked lists then join both
Node* divide(int N, Node *head){
    Node *odd=NULL, *even=NULL;
    Node *oddL = NULL, *evenL = NULL;
    
    Node* temp = head;
    while (temp) {
        if (temp->data % 2 == 0) { // even
            if (even) {
                evenL->next = temp;
                evenL = temp;
            } else {
                even = evenL = temp;
            }
        } else { // odd
            if (odd) {
                oddL->next = temp;
                oddL = temp;
            } else {
                odd = oddL = temp;
            }
        }
        temp = temp->next;
    }
    if (even) {
        evenL->next = odd;
        if (odd) oddL->next = NULL;
        return even;
    } else {
        return odd;
    }
}

// 2. just rearrange them 
Node* temp = NULL;
Node* divide(int N, Node* &head){
    Node* newHead = head;
    Node* t = head, *prev = NULL;
    while(t != NULL) {
        if(t->data %2 == 0) {
            // delete t
            if(temp == prev) {
                prev = t;
                temp = t;
                t = t->next;
            } else if (temp == NULL) {
                prev->next = t->next;
                t->next = head;
                newHead = t;
                temp = newHead;
                t = prev->next;
            } else {
                prev->next = t->next;
                t->next = temp->next;
                temp->next = t;
                temp = t;
                t = prev->next;
            }
            // add after temp
        }else {
            prev = t;
            t = t->next;
        }
    }
    return newHead;
}