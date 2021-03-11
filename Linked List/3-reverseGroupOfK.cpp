// https://www.geeksforgeeks.org/reverse-a-list-in-groups-of-given-size/
// https://www.geeksforgeeks.org/reverse-linked-list-groups-given-size-set-2/

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

	/* Function to reverse the linked list */
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
	
	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
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
	ll.push(1);
	ll.push(2);
	ll.push(2);
	ll.push(4);
	ll.push(5);
	ll.push(6);
	ll.push(7);
	ll.push(8);

	cout << "Given linked list\n";
	ll.print();

	ll.head = ll.reverse(ll.head, 4);

	cout << "\nReversed Linked list \n";
	ll.print();
	return 0;
}