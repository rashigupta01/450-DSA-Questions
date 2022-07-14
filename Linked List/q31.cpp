// my approach
Node * mergeKLists(Node *arr[], int K)
{
    Node* head = NULL, *tail = NULL;
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    for (int i=0; i<K; i++) {
        pq.push({arr[i]->data, arr[i]});
    }
    while (!pq.empty()) {
        auto ele = pq.top();
        pq.pop();
        if (head==NULL) {
            head = ele.second;
            tail = head;
        } else {
            tail -> next = ele.second;
            tail = tail->next;
        }
        if (ele.second->next) pq.push({ele.second->next->data, ele.second->next});
    }
    return head;
}

// Divide and conquer approach: 
// The idea is to pair up K lists and merge each pair in linear time using O(n) space.
// After the first cycle, K/2 lists are left each of size 2*N. After the second cycle, K/4 lists are left each of size 4*N and so on.
// Repeat the procedure until we have only one list left.

