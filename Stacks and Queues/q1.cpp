// Implement stack

// for push
void push (int a) {
    stack[++top] = a;
}

// for pop 
int pop () {
    return stack[top--];
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