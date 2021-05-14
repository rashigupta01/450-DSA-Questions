class Solution{
  public:
    //Function to merge K sorted linked list.
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
};