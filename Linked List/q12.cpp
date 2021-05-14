// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

// Approach 1 : Use two nested loop to check each element of L1 if appear in L2

// Approach 2 : Hash map can be used. Hash the nodes of L1 
// then iterate through L2 and return first node of L2 that is present in map

// Approach 3 : Find diff in the sizes of both lists then move the larger list ahead by diff
// now go through both list simultaneously and find intersection

// Approach 4 : join the tail of L1 with head of L2
// now the problem is similar to finding entry of loop in linked list

// Approach 5 : two pointer
// As head1 reaches null shift it to head2 similarly for head2, then find the point where they meet
int intersectPoint(Node* head1, Node* head2)
{
    Node* thead1= head1, *thead2 = head2;
    while (thead1 != thead2) {
        thead1 = thead1->next;
        if (!thead1) thead1 = head2;
        thead2 = thead2->next;
        if (!thead2) thead2 = head1;
    }
    return thead1 ? thead1->data : -1;
}