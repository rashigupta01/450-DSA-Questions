// https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/

// Since we need to display or delete middle element we have to use doubly linked list
// Code is reffered from gfg.
#include <bits/stdc++.h>
using namespace std;

class DLLNode { 
	public:
	DLLNode *prev, *next; 
	int data;  

    DLLNode (int a) {
        data = a;
        prev = next = NULL;
    }
}; 

class myStack 
{ 
	public:
	DLLNode *head; 
	DLLNode *mid; 
	int elements; 
}; 

myStack *createMyStack() 
{ 
	myStack *ms = new myStack();
	ms->elements = 0; 
	return ms; 
}; 

void push(myStack *ms, int new_data) 
{ 
	DLLNode* new_DLLNode = new DLLNode(new_data);

    // adding this new node at the beginning
	new_DLLNode->next = ms->head;

	ms->elements++; 

	if (ms->elements == 1) 
		ms->mid = new_DLLNode; 
	
	else { 
		ms->head->prev = new_DLLNode; 

		if(!(ms->elements & 1)) // Update mid if ms->count is even
		ms->mid = ms->mid->prev; 
	} 

	ms->head = new_DLLNode; 
} 

int pop(myStack *ms) 
{ 
	/* Stack underflow */
	if (ms->elements == 0) { 
		cout<<"Stack is empty\n"; 
		return -1; 
	} 

	DLLNode *head = ms->head; 
	int item = head->data; 
	ms->head = head->next; 

	if (ms->head != NULL) 
		ms->head->prev = NULL; 

	ms->elements--; 

	if ((ms->elements) & 1 ) 
		ms->mid = ms->mid->next; 

	delete (head); 

	return item; 
} 

// Function for finding middle of the stack 
int findMiddle(myStack *ms) 
{ 
	if (ms->elements == 0) 
	{ 
		cout << "Stack is empty now\n"; 
		return -1; 
	} 

	return ms->mid->data; 
} 