// same approach is given on gfg article: https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/
class Node {
    public:
    char data;
    Node *prev, *next;
    Node (char ch) {
        data = ch;
        prev = NULL;
        next = NULL;
    }
};

class Solution {
	public:
	    Node* head = NULL;
	    Node* last = NULL;
	    
        void insert (char ch) {
            Node* temp = new Node(ch);
            if (head) {
                last -> next = temp;
                temp -> prev = last;
                last = temp;
            } else {
                head = last = temp;
            }
        }
        
        void removeNode (Node* del) {
            if (head == del) {
                if (last == head) {
                    head = last = NULL;
                } else {
                    head = head->next;
                    head->prev = NULL;
                }
            } else {
                del->prev->next =  del->next;
                
                if (last==del) {
                    last = del->prev;
                } else {
                    del->next->prev = del->prev;
                }
            }
            delete del;
        }
        
		string FirstNonRepeating(string A){
		    vector<int> ct (26, 0);
		    vector<Node*> add (26, NULL);
		    string res = "";
		    
		    for (int i=0; i<A.size(); i++) {
		        ct[A[i] - 'a']++;
		        if (ct[A[i] - 'a'] == 1) {
		            insert (A[i]);
		            add[A[i]-'a'] = last;
		        } else if (ct[A[i] - 'a'] == 2) {
		            removeNode (add[A[i]-'a']);
		        }
		        
		        if (head) {
		            res += head->data;
		        } else {
		            res += '#';
		        }
		    }
		    return res;
		}
};


/*
Queue approach: https://www.geeksforgeeks.org/queue-based-approach-for-first-non-repeating-character-in-a-stream/ 

Approach- 
Create a count array of size 26(assuming only lower case characters are present) and initialize it with zero.
Create a queue of char datatype.
Store each character in queue and increase its frequency in the hash array.
For every character of stream, we check front of the queue.
If the frequency of character at the front of queue is one, then that will be the first non-repeating character.
Else if frequency is more than 1, then we pop that element.
If queue became empty that means there are no non-repeating characters so we will print -1.

*/