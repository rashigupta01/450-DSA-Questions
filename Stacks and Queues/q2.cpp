// Implement queue

int front=-1, rare=-1, size = 100;

// for push
void enqueue (int a) {
    queue[(rare+1)%size] = a;
    if (front == -1) {
        front = 0;
        queue[rare] = a;
    }
}

// for pop 
int dequeue () {
    int temp = queue[front];
    if (front == rare) front = rare = -1; 
    else front = (front+1)%size;
    return temp;
}

// for peek
int peek () {
    return queue[front];
}

// checking underflow
bool is_empty () {
    return front == -1;
}

// checking overflow
bool is_full () {
    return (rare+1)%size == front;
}