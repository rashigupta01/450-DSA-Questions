void insertAtCorrectPos (stack<int> &s, int a) {
    if (s.empty() || s.top()<=a) {
        s.push(a);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtCorrectPos (s, a);
    s.push(num);
}

void SortedStack :: sort()
{
    if (s.empty()) return;
    
    int a = s.top();
    s.pop();
    sort ();
    insertAtCorrectPos (s, a);
}

// for iterative version : https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/