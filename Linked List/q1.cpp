// Iterative approach
void reverse()
{
	Node* prev = NULL;
	Node* cur = head;
	Node* next = NULL;
	while(cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
}

// Reccursive approach: https://www.geeksforgeeks.org/reverse-a-linked-list/
Node* reverse(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	/* reverse the rest list and put
		the first element at the end */
	Node* rest = reverse(head->next);
	head->next->next = head;

	/* tricky step -- see the diagram */
	head->next = NULL;

	/* fix the head pointer */
	return rest;
}
