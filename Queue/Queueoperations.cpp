#include <iostream>
#include <queue>
using namespace std; 



class Queue {
	
	int front ; 
	int rear; 
	int peak ;
	int Arr[5]; 
public :
	Queue (){
		front = -1; 
		rear = -1 ; 
	}
	 void enqueue (int value ){
	 	
	 	if (front == 0 && rear == 4){
	 		cout << "Queue is full "<< endl;
			}
	 		
	 	else if 
	 		(front == -1 && rear ==-1  ){
	 		 rear = front  = 0;
			   Arr[rear] = value ;   // When you insert a new element (num) into the queue,
			   							// you store it at the position indicated by the rear index in the array Q.
			 }
			else {
				rear ++ ; 
				Arr[rear ] = value ; 
			}
			 
		 
	 }
	 
	 
	 
	 void dequeue ( ){
	 	cout << endl; 
	 	if ( front ==-1  || front > rear ){
	 		cout << "Queue is empty . Nothing to dequeue  "<< endl ;
	 
		 }else if ( front == rear ){
		 	front = rear = -1 ; 
		 	
		 }else{
		 	 
		 	 // Arr[front ];
			 front ++; 
		 }
		 
		 
		 
		 
	 }
	 
	 
//	 void peak (){
//	 	
//	 }
	 
	 
	 
	 
	 
	 
	 
	 void display (){
	 	 
	 	if ( front == -1 || front > rear ){
	 		cout << " Queue is empty . Nothing to show "<< endl; 
	 		return ;
	 	}
	 	cout << " Elements in the queue are : "<< endl; 
	 	for (int i = front ; i<= rear ; i++ ){
	 		cout << Arr[i]<< " ";
		 }
	 }
};



int main (){
	Queue q1; 
	q1.enqueue(14);
	q1.enqueue(18); 
	q1.enqueue(16);

 q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.dequeue();
	q1.display();
	q1.display();
	
}
