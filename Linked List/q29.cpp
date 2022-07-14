// simple approach:
// count freq of zero, one, two and then traverse again to fill the linked list in order of first zero then one then two


// maintain three linked lists (order is important, stable algo)
Node* segregate(Node *head) {
    
    Node *one = NULL, *two = NULL, *zero = NULL;
    Node *oneLast = NULL, *twoLast = NULL, *zeroLast = NULL;
    Node* temp = head;
    while (temp) {
        if (temp->data == 0) {
            if (zero) {
                zeroLast->next = temp;
                zeroLast = temp;
            } else {
                zero = zeroLast = temp;
            }
        } else if (temp->data == 1) {
            if (one) {
                oneLast->next = temp;
                oneLast = temp;
            } else {
                one = oneLast = temp;
            }
        } else {
            if (two) {
                twoLast->next = temp;
                twoLast = temp;
            } else {
                two = twoLast = temp;
            }
        }
        temp = temp->next;
    }

    if (zero) {
        if (one) {
            zeroLast->next = one;
            oneLast->next = two;
        } else {
            zeroLast->next = two;
        }
        if (two) twoLast->next = NULL;
        return zero;
    } else {
        if (one) {
            oneLast->next = two;
            if (two) twoLast -> next = NULL;
            return one;
        } else {
            return two;
        }
    }
}