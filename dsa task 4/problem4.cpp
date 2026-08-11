#include <iostream>
#define SIZE 5  
using namespace std;

class CircularQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    void enqueue(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) {  
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        queue[rear] = value;
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued: " << queue[front] << endl;
        if (front == rear) { 
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % SIZE) {
            cout << queue[i] << " ";
        }
        cout << queue[rear] << endl;  
    }
};

int main() {
    CircularQueue c;
    
  c.enqueue(10);
    c.enqueue(20);
    c.enqueue(30);

    c.display();

    c.dequeue();
    c.display();

    return 0;
}

