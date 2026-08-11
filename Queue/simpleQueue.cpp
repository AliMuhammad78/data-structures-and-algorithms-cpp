#include<iostream>
#include<stack>
using namespace std;

class Queue{
	stack<int> s1,s2;
	int rear,front;
	int Q[5];
	public:
		Queue(){
			rear=front=-1;
		}
		
		void enqueue(int num){
			if(front==0 && rear==4){
				cout<<"Queue is full "<<endl;
			}
			else if(front==-1 && rear==-1){
				rear=front=0;
				Q[rear]=num;
			}
			else
			{
				rear++;
				Q[rear]=num;
			}
		}
		
		void dequeue(){
			if((front==-1) && (rear==-1)){
				cout<<"Queue is empty "<<endl;
			}
			else if(rear==front){
				rear=front=-1;
			}
			else{
				int n=Q[front];
				front++;
			}
		}
		
		void Display(){
			if(front==-1 && rear==-1){
				cout<<"Queue is empty "<<endl;
			}
			else
			{
				cout<<"The  elements in the Queue are :";
				for(int i=front;i<=rear;i++){
					cout<<Q[i]<<" ";
				}
				cout<<endl;
			}
			
		}
};

int main(){
	Queue q1;
	q1.enqueue(10);
	q1.enqueue(15);
	q1.enqueue(20);
	q1.enqueue(25);
	q1.enqueue(30);
	q1.Display();
	
	q1.dequeue();
	q1.dequeue();
	q1.Display();
	
	q1.dequeue();
	q1.dequeue();
	q1.Display();

}
