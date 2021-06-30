
// used doubly linked list and unordered map

struct Node {
    int data;
    Node *prev, *next;
    
    Node(int val) {
        data = val;
        prev = next = NULL;
    }
};

void push_front (Node* curpage, Node* head) {
    curpage->next = head->next;
    curpage->prev = head;
    head->next->prev = curpage;
    head->next = curpage;
}

void pop_back (Node* tail) {
    Node* temp = tail->prev;
    temp->prev->next = tail;
    tail->prev = temp->prev;
    delete temp;
}

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        Node* head = new Node(-1);
        Node* tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        
        unordered_map <int, Node*> present;
        int size = 0, pagefault = 0;
        
        for (int i=0; i<N; i++) {
            if (present.find(pages[i]) != present.end()) {
                Node* curpage = present[pages[i]];
                curpage->prev->next = curpage->next;
                curpage->next->prev = curpage->prev;
                
                push_front (curpage, head);
            } else {
                pagefault ++;
                
                if (size == C) {
                    size--;
                    present.erase(tail->prev->data);
                    pop_back (tail);
                }
                size++;
                present[pages[i]] = new Node (pages[i]);
                push_front (present[pages[i]], head);
            }
        }
        return pagefault;
    }
};