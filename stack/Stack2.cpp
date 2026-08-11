//#include<iostream>
//using namespace std;
//
//class Stack{
//    int size;
//	int array[5];
//	int top;
//	public:
//		Stack(){
//			top=-1;
//		}
//		void push(int num){
//			if(top==4){
//				cout<<"Stack is overflow"<<endl;
//			}else{
//			    top++;
//			    array[top]=num;
//		    }
//		}
//		int  pop(){
//			if(top==-1){
//				cout<<"Stack is underflow"<<endl;
//				return -1;
//			}else{
//				int temp=array[top];
//				top--;
//				return temp;
//			}
//		}
//		void display(){
//			if(top==-1){
//				cout<<"Stack is empty"<<endl;
//			}else{
//			cout<<"top current value is :"<<top<<endl;
//			cout<<"The total element in stack are :"<<endl;
//			for(int i=0;i<=top;i++){
//				cout<<i<<"-> "<<array[i]<<endl;
//			   }
//		    }
//	    }
//	    void transfer(Stack& s1,Stack& s2){
//	    	while(s1.top>=0){
//	    		int value=s1.pop();
//	    		if(value!=-1){
//	    			s2.push(value);
//				}
//			}
//		}
//		void copy(Stack& s1,Stack& s2){
//	    	if(s1.top>=0){
//	    	    for(int i=0;i<=s1.top;i++){
//	    		    s2.push(s1.array[i]);
//			    }
//			}
//		}
//};
//
//
//int main(){
//	Stack s1,s2;
//	s1.push(23);
//	s1.push(24);
//    s1.push(56);
//	s1.push(67);
//	s1.push(89);
//    s1.display();
//    
//    cout<<"Transfering value from stack 1 to stack 2 ..."<<endl;
//    s2.copy(s1,s2);
//    s2.display();
//    
//    s1.display();
//
//	
//}
//


//  					using third stack 


#include <iostream>
using namespace std;

class Stack {
    int array[5];  // Stack storage with a fixed size
    int top;       // Index of the top element

public:
    Stack() {
        top = -1;  // Initialize an empty stack
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == 4;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow" << endl;
        } else {
            array[++top] = value;  // Increment top and insert value
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
            return -1;  // Return -1 for underflow condition
        } else {
            return array[top--];  // Return top element and decrement top
        }
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = 0; i <= top; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
};

void transferStack(Stack& s1, Stack& s2) {
    Stack temp;  // Temporary stack

    // Step 1: Transfer elements from s1 to temp to reverse order
    while (!s1.isEmpty()) {
        temp.push(s1.pop());
    }

    // Step 2: Transfer elements from temp to s2 to restore original order
    while (!temp.isEmpty()) {
        s2.push(temp.pop());
    }
}

int main() {
    Stack s1, s2;

    // Push some elements onto s1
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << "Original Stack (s1): ";
    s1.display();

    // Transfer elements from s1 to s2
    transferStack(s1, s2);

    cout << "Stack (s1) after transfer: ";
    s1.display();  // Should be empty

    cout << "Stack (s2) after transfer: ";
    s2.display();  // Should contain elements of s1 in the same order

    return 0;
}

