// Circular queue

// keep two variables front and rare
// enqueue : rare = (rare+1)%N
// isfull : (rare+1)%N == front
// dequeue : front = (front+1)%N
// isempty : front == -1