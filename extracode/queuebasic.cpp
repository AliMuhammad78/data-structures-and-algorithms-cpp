#include <iostream>
using namespace std;

#define MAX 5  // Define maximum size of the queue

class Queue {
private:
    int front;
    int rear;
    int arr[MAX];  // Array to store queue elements
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool fullQueue() {
        return (rear == MAX - 1);
    }

    // Function to check if the queue is empty
    bool emptyQueue() {
        return (front == -1 || front > rear);
    }

    // Function to add an element to the queue (enqueue)
    void enqueue(int value) {
        if (fullQueue()) {
            cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        if (front == -1) front = 0;  // If inserting first element, move front to 0
        rear++;
        arr[rear] = value;
        cout << value << " enqueued successfully.\n";
    }

    // Function to remove an element from the queue (dequeue)
    void dequeue() {
        if (emptyQueue()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        front++;
        if (front > rear) {  // Reset queue if all elements are dequeued
            front = rear = -1;
        }
    }

    // Function to get the element at the front (peek)
    void peek() {
        if (emptyQueue()) {
            cout << "Queue is empty! No element to peek.\n";
            return;
        }
        cout << "Front element is: " << arr[front] << endl;
    }

    // Function to sort the queue
    void sortQueue() {
        if (emptyQueue()) {
            cout << "Queue is empty! Cannot sort.\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            for (int j = i + 1; j <= rear; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        cout << "Queue sorted successfully.\n";
    }

    // Function to display the queue
    void displayQueue() {
        if (emptyQueue()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Sort Queue\n";
        cout << "7. Display Queue\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!0q.fullQueue()) {
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
            } else {
                cout << "Queue is full!\n";
            }
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            if (q.emptyQueue()) {
                cout << "Queue is empty.\n";
            } else {
                cout << "Queue is not empty.\n";
            }
            break;

        case 5:
            if (q.fullQueue()) {
                cout << "Queue is full.\n";
            } else {
                cout << "Queue is not full.\n";
            }
            break;

        case 6:
            q.sortQueue();
            break;

        case 7:
            q.displayQueue();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}

