// https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/

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

	void removeDuplicates()
    {
        Node* ptr1 = head;
        while(ptr1 && ptr1->next) {
            int data = ptr1->data;
            Node* ptr2 = ptr1->next;
            while(ptr2 && ptr2->data == data) {
                ptr2 = ptr2->next;
            }
            ptr1->next = ptr2;
            ptr1 = ptr2;
        }
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
	ll.push(13);
	ll.push(2);
	ll.push(2);
	ll.push(7);
    ll.push(7);

	cout << "Given linked list\n";
	ll.print();

	cout << endl;

    ll.removeDuplicates();
	cout << "Duplicates removed\n";
	ll.print();
	return 0;
}