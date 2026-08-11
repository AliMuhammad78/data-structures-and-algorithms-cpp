#include <stack>
#include <iostream>
using namespace std;

class MyQueue {
private:
    stack<int> stack1;  // This stack will be used for push operations
    stack<int> stack2;  // This stack will be used for pop/peek operations

public:
    // Push element x to the back of queue
    void push(int x) {
        stack1.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        if (stack2.empty()) {
            // Transfer elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    // Get the front element
    int peek() {
        if (stack2.empty()) {
            // Transfer elements from stack1 to stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(3);
    q.push(5);
    q.push(34);
    cout << "Front element: " << q.peek() << endl; // returns 1
    cout << "Popped element: " << q.pop() << endl;  // returns 1
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // returns false

    return 0;
}

