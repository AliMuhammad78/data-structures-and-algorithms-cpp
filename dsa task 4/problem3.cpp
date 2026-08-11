#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<int> queue) {
    stack<int> stack;
    int size = queue.size();
 
 
    for (int i = 0; i < size; i++) {
        stack.push(queue.front());
        queue.pop();
    }

    
    for (int i = 0; i < size; i++) {
        if (stack.top() != queue.front()) {
            return false;
        }
        stack.pop();
        queue.push(queue.front());
        queue.pop();
    }
    return true;
}

int main() {
    queue<int> queue;

   
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(2);
    queue.push(1);

    cout << "Is Palindrome: " << (isPalindrome(queue) ? "True" : "False") << endl;

    return 0;
}

