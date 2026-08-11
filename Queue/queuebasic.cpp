 #include <iostream> 
#include <queue>
using namespace std;

#define n 20

class Queue {
private:
    int front; 
    int back; 
    int arr[n];  // Correctly declare array of size n

public:
    Queue() {
        front = -1;
        back = -1;
    }
    
    void enqueue(int x) {
        if (back == n - 1) {
            cout << "Queue overflow" << endl; 
            return; 
        }
        back++; 
        if (front == -1) front = 0;  // Set front to 0 if queue was empty
        arr[back] = x;  // Add element to the array
    }
    
    void dequeue() {
        if (front == -1 || front > back) {
            cout << "No elements in queue" << endl;
            return; 
        }
        front++; 
        if (front > back) {
            front = back = -1;  // Reset if all elements are dequeued
        }
    }
    
    int peek() {
        if (front == -1 || front > back) {
            cout << "There is no element in the queue" << endl;
            return -1;  // Return -1 to indicate empty queue
        }
        return arr[front];  // Return front element
    }
    
    bool isEmpty() {
        return front == -1 || front > back; 
    }
    
    void display() {
        if (front == -1 || front > back) {
            cout << "There is nothing to display" << endl; 
            return; 
        }
        cout << "Queue elements are: ";
        for (int i = front; i <= back; i++) {
            cout << arr[i] << " "; 
        }
        cout << endl; 
    }
};

int main() {
    Queue q; 
    q.enqueue(89);
    q.enqueue(93);
    q.enqueue(20);
    q.dequeue();
    q.display(); 
    
    return 0;
}

