Node* revListInGroupOfGivenSize(Node* head, int k)
{
    if (!head) return head;
    
	Node* temp = head;
	Node* prev = NULL;
	int count = 0;
	while (temp && count<k) {
	    temp->prev = temp->next;
	    temp->next = prev;
	    count++;
	    prev = temp;
	    temp = temp->prev;
	}
	head->next = revListInGroupOfGivenSize(temp, k);
    if(head->next) head->next->prev = head;
	return prev;
}