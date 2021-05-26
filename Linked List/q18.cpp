// used stack
bool isPalindrome(Node *head)
{
    if (!head) return true;
    
    Node *slow=head, *fast=head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp=head;
    stack <int> s;
    while (temp!=slow) {
        s.push(temp->data);
        temp = temp->next;
    }
    if (fast) {
        slow = slow->next;
    }
    while (slow) {
        if (s.top() != slow->data) return false;
        s.pop();
        slow = slow->next;
    }
    return true;
}

// https://www.geeksforgeeks.org/function-to-check-if-a-singly-linked-list-is-palindrome/
// Approach 2: reverse the second half of linked list
// check if the two halves are same or not 
Node* reverse(Node* slow) {
    Node* curr=slow;
    Node* next;
    Node* prev=NULL;
    while(curr!=NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    } 
    fast=head;
    slow=reverse(slow);
    while(slow!=NULL) {
        if(fast->data!=slow->data) {
            return false;
        }  
        slow=slow->next;
        fast=fast->next;
    } 
    return true;
}

// Approach 3: recursion
// idea is to use two pointers left and right and check left and right's data.
// pass left as double pointer and update it before returning from the current function call.