// same ques: q31

// my approach: O(N M logN)
Node *flatten(Node *root)
{    
    Node* head = NULL, *tail = NULL;
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    Node* temp = root;
    while (temp) {
        pq.push({temp->data, temp});
        temp = temp->next;
    }
    while (!pq.empty()) {
        auto ele = pq.top();
        pq.pop();
        if (head==NULL) {
            head = ele.second;
            tail = head;
        } else {
            tail -> bottom = ele.second;
            tail->next = NULL;
            tail = tail->bottom;
        }
        if (ele.second->bottom) pq.push({ele.second->bottom->data, ele.second->bottom});
    }
    return head;
}

// merge two lists at a time