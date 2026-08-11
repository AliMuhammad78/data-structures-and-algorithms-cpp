 #include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    // Constructor to initialize the queue
    Queue(int s) {
        size = s;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Function to insert elements into the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (front == -1) front = 0;  // Initialize front to 0 if inserting the first element.
        rear++;
        arr[rear] = value;
    }

    // Function to remove elements from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;  // Return -1 if queue is empty.
        }
        int temp = arr[front];
        front++;
        if (front > rear) {  // Reset queue if all elements are dequeued.
            front = rear = -1;
        }
        return temp;
    }

    // Function to display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Function to merge two queues into a third queue
void mergeQueues(Queue &q1, Queue &q2, Queue &q3) {
    // Dequeue from both queues and enqueue into the third queue
    while (!q1.isEmpty() || !q2.isEmpty()) {
        if (!q1.isEmpty()) {
            int val = q1.dequeue();
            q3.enqueue(val);
        }
        if (!q2.isEmpty()) {
            int val = q2.dequeue();
            q3.enqueue(val);
        }
    }
}

int main() {
    // Create two queues of size 5
    Queue q1(5), q2(5), q3(10);  // q3 size is 10 to hold elements from both queues

    // Inserting elements into Queue 1
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);

    // Inserting elements into Queue 2
    q2.enqueue(4);
    q2.enqueue(5);
    q2.enqueue(6);

    // Display original queues
    cout << "Queue 1: ";
    q1.display();
    cout << "Queue 2: ";
    q2.display();

    // Merge Queue1 and Queue2 into Queue3
    mergeQueues(q1, q2, q3);

    // Display the merged queue
    cout << "Merged Queue (Queue 3): ";
    q3.display();

    return 0;
}

