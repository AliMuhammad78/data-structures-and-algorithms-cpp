#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseQueue(queue<int> queue) {
    stack<int> stack;

 
    while (!queue.empty()) {
        stack.push(queue.front());
        queue.pop();
    }

     
    while (!stack.empty()) {
        queue.push(stack.top());
        stack.pop();
    }

    return queue;
}

int main() {
    queue<int> queue;

 
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    queue = reverseQueue(queue);

    cout << "Reversed Queue: ";
    while (!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }

    return 0;
}

