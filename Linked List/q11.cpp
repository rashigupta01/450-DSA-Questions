// two pointer kind of approach
Node* findIntersection(Node* head1, Node* head2)
{
    Node *res = NULL, *tail = NULL;
    while (head1 && head2) {
        if (head1->data == head2->data) {
            if (!res) {
                res = new Node (head1->data);
                tail = res;
            } else {
                tail -> next = new Node (head1->data);
                tail = tail->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        } else if (head1->data > head2->data) {
            head2 = head2->next;
        } else {
            head1 = head1->next;
        }
    }
    return res;
}