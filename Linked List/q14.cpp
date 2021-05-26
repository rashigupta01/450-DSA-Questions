
// I created two linked lists using the existent nodes only and then connect both of them with pivot
// On gfg just links are manipulated : https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
void quickSort(struct node **headRef) {
    if (*headRef == NULL) return;
    
    node* h1 = NULL, *h2 = NULL, *pivot = *headRef, *temp = (*headRef)->next;
    while (temp) {
        node* next = temp->next;
        temp->next = NULL;
        
        if (temp->data < pivot->data) {
            h1 = push(h1, temp);
        } else {
            h2 = push (h2, temp);
        }
        temp = next;
    }
    quickSort (&h1);
    quickSort (&h2);
    
    node* tail = h1;
    while (tail && tail->next) {
        tail = tail->next;
    }
    if (h1)
        tail->next = pivot;
    else {
        h1 = pivot;
    }
    pivot->next = h2;
    *headRef = h1;
}