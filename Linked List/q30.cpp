// My approach : Space O(n)
// store the maping of nodes in original list and new list in a map
// using this map update values for next and arb in new list
// https://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/
Node *copyList(Node *head)
{
    Node* temp = head;
    unordered_map <Node*, Node*> mp;
    
    while (temp) {
        Node* newNode = new Node(temp->data);
        mp[temp] = newNode;   
        temp = temp->next;
    }
    temp = head;
    Node* newHead = mp[head];
    Node* temp2 = newHead;
    // temp = temp->next;
    while (temp) {
        if (temp->next) temp2->next = mp[temp->next];
        if (temp->arb) temp2->arb = mp[temp->arb];
        temp = temp->next;
        temp2 = temp2->next;
    }
    return newHead;
}

// O(1) space approach:https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/
/*
1. add the copy of Nth node between the Nth and N+1th node 
2. Now copy the random link in this fashion 
    original->next->random= original->random->next;  (TRAVERSE TWO NODES) 
3. Now restore the original and copy linked lists in this fashion in a single loop. 
    original->next = original->next->next;
    copy->next = copy->next->next;
*/