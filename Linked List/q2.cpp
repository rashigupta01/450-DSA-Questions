// * Reccursive approach : https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
Node *reverse (Node *head, int k)
{ 
	if(head==NULL) {
		return head;
	}
	int count = 0;
	Node *curr = head, *next=NULL, *prev=NULL;
	while(curr!=NULL && count<k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	head->next = reverse(curr, k);
	return prev;   
}

// * Iterative approach : https://www.geeksforgeeks.org/reverse-linked-list-groups-given-size-set-2/
struct Node* Reverse(struct Node* head, int k)
{
    // Create a stack of Node*
    stack<Node*> mystack;
    struct Node* current = head;
    struct Node* prev = NULL;
  
    while (current != NULL) {
  
        // Terminate the loop whichever comes first
        // either current == NULL or count >= k
        int count = 0;
        while (current != NULL && count < k) {
            mystack.push(current);
            current = current->next;
            count++;
        }
  
        // Now pop the elements of stack one by one
        while (mystack.size() > 0) {
  
            // If final list has not been started yet.
            if (prev == NULL) {
                prev = mystack.top();
                head = prev;
                mystack.pop();
            } else {
                prev->next = mystack.top();
                prev = prev->next;
                mystack.pop();
            }
        }
    }
  
    // Next of last element will point to NULL.
    prev->next = NULL;
  
    return head;
}