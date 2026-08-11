#include<iostream>
using namespace std;

class Stack{
    int size;
	int array[5];
	int top;
	public:
		Stack(){
			top=-1;
//			cout<<"Enter the size of the array"<<endl;
//			cin>>size;
		}
		void push(int num){
			if(top==4){
				cout<<"Stack is overflow"<<endl;
			}else{
			    top++;
			    array[top]=num;
		    }
		}
		void pop(){
			if(top==-1){
				cout<<"Stack is underflow"<<endl;
			}else{
				top--;
			}
		}
		void display(){
			if(top==-1){
				cout<<"Stack is empty"<<endl;
			}else{
			cout<<"top current value is :"<<top<<endl;
			cout<<"The total element in stack are :"<<endl;
			for(int i=0;i<=top;i++){
				cout<<i<<"-> "<<array[i]<<endl;
			}
		}
	}
};


int main(){
	Stack p;
	p.push(23);
	p.push(24);
    p.push(56);
	p.push(67);
	p.push(89);
    p.display();
    
	p.pop();
	p.pop();
	p.pop();
	p.display();
	
	p.push(98);
	
	p.pop();
	p.pop();
	p.pop();
	p.pop();
	p.display();
	
}

