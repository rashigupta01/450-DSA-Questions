// My approach: 
class Solution
{
    public:
    
    bool util(Node *head) 
    {
        if (!head->next) {
            head->data = (head->data+1)%10;
            if (head->data) return false;
            else return true;
        }
        if (util(head->next)) {
            head->data = (head->data+1)%10;
            if (head->data) return false;
            else return true;
        }
        else return false;
    }
    Node* addOne (Node *head) {
        if (util (head)) {
            Node* newhead = new Node (1);
            newhead->next = head;
            head = newhead;
        }
        return head;
    }
};

// Approach 2 :
// Reverse the list and keep adding 1 to nodes while there is a carry, at the end if carry is still there then create a new node

// Approach 3 : https://www.geeksforgeeks.org/add-one-to-a-number-represented-as-linked-list-set-2/?ref=rp
