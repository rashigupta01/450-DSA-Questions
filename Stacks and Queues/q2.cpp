// Implement queue

int front=-1, rare=-1;

// for push
void enqueue (int a) {
    if (front == -1) {
        front  = rare = 0;
        queue[rare] = a;
    } else 
        queue[++rare] = a;
}

// for pop 
int dequeue () {
    front++;
    if (front > rare) front = rare = -1;
    return queue[front++];
}

// for peek
int peek () {
    return stack[top];
}

// checking underflow
bool is_empty () {
    return top == -1;
}

// checking overflow
bool is_full () {
    return top == MAX_SIZE-1;
}