// https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/

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

	Node* firstNodeOfLoop()
	{
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) {
                Node* temp = head;
				while(true) {
					if(temp == slow) {
						return temp;
					}
					temp = temp->next;
					slow = slow->next;
				}
            }
        }
        return NULL;
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
    ll.head->next->next->next->next->next = ll.head->next;

	// cout << "Given linked list\n";
	// ll.print();

    cout<<ll.firstNodeOfLoop()->data;
	cout << endl;
	return 0;
}