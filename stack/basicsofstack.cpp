#include <iostream>
using namespace std;

class Stack {
    int arr[5];   // Predefined array of size 5
    int top;      // Index of the top element

public:
    // Constructor to initialize stack
    Stack() {
        top = -1;  // Stack is initially empty
    }

    // Push function: Adds an element to the stack
    void push(int value) {
        if (top == 4) {  // Check for overflow (array size is 5)
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;  // Increment top and store the value
        cout << value << " pushed onto the stack." << endl;
    }

    // Pop function: Removes the top element from the stack
    void pop() {
        if (top == -1) {  // Check for underflow
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << arr[top--] << " popped from the stack." << endl;  // Remove the top element
    }

    // Display function: Shows all elements in the stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;  // Create a stack

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);  // This will show "Stack Overflow"

    s.display();

    s.pop();
    s.pop();
    s.display();

    s.pop();
    s.pop();
    s.pop();
    s.pop();  // This will show "Stack Underflow"

    return 0;
}

