void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    
    if (!head) {
        *head1_ref = NULL;
        *head2_ref = NULL;
        return;
    }
    if (head->next  == head) {
        *head1_ref = head;
        *head2_ref = NULL;
        return;
    }
    Node *slow=head, *fast=head, *prevslow = NULL, *prevfast=NULL; 
    bool flag = true;
    while (flag || (fast!=head && fast->next!=head)) {
        flag = false;
        prevslow=slow;
        slow=slow->next;
        prevfast = fast->next;
        fast = fast->next->next;
    }
    Node* tail1;
    if (fast==head) {   // even
        tail1 = prevslow;
    } else {
        tail1 = slow;
    }
    *head1_ref = head;
    *head2_ref = tail1->next;
    tail1->next = head;
    if (fast!=head) {
        fast->next = *head2_ref;
    } else {
        prevfast->next = *head2_ref;
    }
}

// Simplified code given on gfg : https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
void splitList(Node *head, Node **head1_ref, Node **head2_ref) { 
    Node *slow_ptr = head; 
    Node *fast_ptr = head; 
      
    if(head == NULL) 
        return; 
      
    /* If there are odd nodes in the circular list then 
       fast_ptr->next becomes head and for even nodes 
       fast_ptr->next->next becomes head */
    while(fast_ptr->next != head && fast_ptr->next->next != head) { 
        fast_ptr = fast_ptr->next->next; 
        slow_ptr = slow_ptr->next; 
    } 
      
    /* If there are even elements in list
       then move fast_ptr */
    if(fast_ptr->next->next == head) 
        fast_ptr = fast_ptr->next; 
          
    /* Set the head pointer of first half */
    *head1_ref = head; 
          
    /* Set the head pointer of second half */
    if(head->next != head) 
        *head2_ref = slow_ptr->next; 
          
    /* Make second half circular */
    fast_ptr->next = slow_ptr->next; 
          
    /* Make first half circular */
    slow_ptr->next = head; 
} 