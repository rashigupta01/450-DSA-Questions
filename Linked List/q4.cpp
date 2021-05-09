// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	/* Function to detect loop in linked list (floyd method) */
	bool detectLoopFloyd_1()
	{
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL) {
			fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                Node* temp = head;
				while(true) {
					Node* temp2 = slow;
					while(temp2->next != slow) {
						if(temp2->next  == temp) {
							temp2 -> next = NULL;
							return true;
						}
						temp2 = temp2->next;
					}
					temp = temp -> next;
				}
            }
        }
        return false;
	}

	bool detectLoopFloyd_2()		// Most efficient one
	{
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                Node* temp = head;
				if(slow == head) {
                    while(temp->next!=head) {
						temp = temp->next;
					}
					temp->next = NULL;
                    return true;
                }
				while(true) {
					if(temp->next == slow->next) {
						slow->next = NULL;
						return true;
					}
					temp = temp->next;
					slow = slow->next;
				}
            }
        }
        return false;
	}

    bool detectLoopSet() {
        unordered_set<Node*> nodesvisited;
        Node* temp = head;
        while(temp->next!=NULL) {
            nodesvisited.insert(temp);
            
            if(nodesvisited.find(temp->next)!=nodesvisited.end()) {
                temp->next=NULL;
                return true;
            }
            temp = temp->next;
        } 
        return false;
    }

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}

    /* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);
    ll.push(12);
    ll.head->next->next->next->next->next = ll.head;

	// cout << "Given linked list\n";
	// ll.print();

    if(ll.detectLoopFloyd_2()) {
        cout<<"Loop exists"<<endl;
        ll.print();
    } else {
        cout<<"Loop does not exists";
    }
	cout << endl;
	return 0;
}