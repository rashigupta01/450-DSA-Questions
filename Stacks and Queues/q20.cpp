// two alternates:
// i) make enqueue O(n)
// ii) make dequeue O(n)

// i) push: enqueu ele in q2 then dequeue everything from q1 and enqueue to q2. at last swap the queue

// ii) pop: dequeu except last element from q1 and enqueue in q2. empty q1 and swap the queues 

// Implementation of second approach \|/
//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    if (q1.empty()) return -1;
    
    while (q1.size()>1) {
        q2.push(q1.front());
        q1.pop();
    }
    int num = q1.front();
    q1.pop();
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    
    return num;
}

// **space optimized: using only one queue
// for push: push the element, pop n-1 times and keep pushing simultaneously
// for pop: normal pop