// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/

// Floyd’s Cycle-Finding Algorithm
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

// Hashing approach using set
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

