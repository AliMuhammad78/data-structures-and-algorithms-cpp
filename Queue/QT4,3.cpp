#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool IsPalindrome(queue<int> q1) {
    stack<int> s1;
    queue<int> TestingQueue = q1; 

    
    while (!q1.empty()) {
        s1.push(q1.front());
        q1.pop();
    }

    while (!TestingQueue.empty()) {
        if (TestingQueue.front() != s1.top()) {
            return false; 
        }
        TestingQueue.pop();
        s1.pop();
    }

    return true; 
}

int main() {
    queue<int> q;
    
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(4);
    q.push(5);

   
    if (IsPalindrome(q)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

