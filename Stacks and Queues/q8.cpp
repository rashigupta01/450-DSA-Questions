// My approach: same as second approach on https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/
// Visit this link for space optimization: https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/

stack<int> curmin;
int count = 0;

void push(stack<int>& s, int a){
	if (isEmpty(s) || curmin.top()>=a) {
	    curmin.push(a);
	}
	s.push(a);
	count++;
}

bool isFull(stack<int>& s,int n){
	return count >= n;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
    int temp = s.top();
    if (s.top() == curmin.top()) {
        curmin.pop();
    }
    count--;
    s.pop();
    return temp;
}

int getMin(stack<int>& s){
    return curmin.top();
}