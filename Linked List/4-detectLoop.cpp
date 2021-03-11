// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

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
	bool detectLoopFloyd()
	{
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) return true;
        }
        return false;
	}

    bool detectLoopSet() {
        unordered_set<Node*> nodesvisited;
        Node* temp = head;
        while(temp!=NULL) {
            if(nodesvisited.find(temp)!=nodesvisited.end()) {
                return true;
            }
            nodesvisited.insert(temp);
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

	// cout << "Given linked list\n";
	// ll.print();
    ll.head->next->next->next->next->next = ll.head;

    if(ll.detectLoopSet()) {
        cout<<"Loop exists";
    } else {
        cout<<"Loop does not exists";
    }
	cout << endl;
	return 0;
}