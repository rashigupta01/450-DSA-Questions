// My iterative approach using stack
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> temp;
    for (int i=0; i<k; i++) {
        temp.push(q.front());
        q.pop();
        
    }
    queue<int> res;
    for (int i=0; i<k; i++) {
        res.push(temp.top());
        temp.pop();
    }
    
    while (!q.empty()) {
        res.push(q.front());
        q.pop();
    }
    return res;
}