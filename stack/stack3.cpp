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
//	    void sumstack(Stack& s3,Stack& s1,Stack& s2){
//	    	Stack temp;
//	    	while(s1.top>=0 && s2.top>=0){
//	    		int value=s1.pop()+s2.pop();
//	    		if(value!=-1){
//	    			temp.push(value);
//				}
//			}
//			
//// 			while(temp.top>=0){
////	    		int value=temp.pop();
////	    		if(value!=-1){
////	    			s3.push(value);
////				}
////			}
////		}
//	
//};
//
//
//int main(){
//	Stack s1,s2,s3;
//	s1.push(10);
//	s1.push(20);
//    s1.push(30);
//	s1.push(40);
//	s1.push(50);
//    s1.display();
//    
//    s2.push(10);
//	s2.push(20);
//    s2.push(30);
//	s2.push(40);
//	s2.push(50);
//    s2.display();
//    
//    s3.sumstack(s3,s1,s2);
//    s3.display();
//    
//    
//
//	return 0; 
//}





#include <iostream>
using namespace std;

class Stack {
    int size;
    int array[5];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(int num) {
        if (top == 4) {
            cout << "Stack is overflow" << endl;
        } else {
            top++;
            array[top] = num;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack is underflow" << endl;
            return -1;
        } else {
            int temp = array[top];
            top--;
            return temp;
        }
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top current value is: " << top << endl;
            cout << "The total elements in stack are:" << endl;
            for (int i = 0; i <= top; i++) {
                cout << i << " -> " << array[i] << endl;
            }
        }
    }

    void sumstack(Stack& s3, Stack& s1, Stack& s2) {
        Stack temp;
        
        // Sum elements while both stacks have elements
        while (s1.top >= 0 && s2.top >= 0) {
            int value = s1.pop() + s2.pop();  // Sum top elements
            if (value != -1) {
                temp.push(value);  // Push the sum onto the temporary stack
            }
        }

        // Transfer the sums from temp to s3
        while (temp.top >= 0) {
            int value = temp.pop();
            if (value != -1) {
                s3.push(value);  // Push each sum to s3
            }
        }
    }
};

int main() {
    Stack s1, s2, s3;

    // Push elements into the first stack
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.display();

    // Push elements into the second stack
    s2.push(5);
    s2.push(15);
    s2.push(25);
    s2.push(35);
    s2.push(45);
    s2.display();

    // Sum the two stacks
    s3.sumstack(s3, s1, s2);
    s3.display();  // Display the results in stack s3

    return 0;
}

