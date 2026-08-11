#include <iostream>
#include <queue>
using namespace std;

queue<int> mergeQueues(queue<int>& queueA, queue<int>& queueB) {
    queue<int> mergedQueue;

    while (!queueA.empty() || !queueB.empty())  {
    	
        if (!queueA.empty()) {
            mergedQueue.push(queueA.front());
            queueA.pop();
        }
        
        if (!queueB.empty()) {
            mergedQueue.push(queueB.front());
            queueB.pop();
        }
    }
    return mergedQueue;
}

int main() {
    queue<int> queueA, queueB;
 
    queueA.push(1);
    queueA.push(3);
    queueA.push(5);

     
    queueB.push(2);
    queueB.push(4);
    queueB.push(6);

    queue<int> mergedQueue = mergeQueues(queueA, queueB);

    cout << "Merged Queue: ";
    while (!mergedQueue.empty()) {
        cout << mergedQueue.front() << " ";
        mergedQueue.pop();
    }

    return 0;
}

