bool isCircular(Node *head)
{
    Node* temp = head;
    while (temp && temp->next != head) {
        temp = temp->next;
    }
    if (temp) return 1;
    else return 0;
}