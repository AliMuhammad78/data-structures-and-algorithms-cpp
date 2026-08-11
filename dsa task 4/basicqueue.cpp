#include <iostream>
using namespace std;

class Queue {
	int rear ; 
	int front ;  
   int size ; 
   int arr[];
public : 
Queue (){
	rear = -1; 
	front = -1 ; 
}

void Emptyqueue (){
	if (rear == -1 , front == -1){
		cout << "Queue is empty ";
	}
} 
 bool Fullqueue (){
 	if (front  == 0 , rear == size -1 ){
 		cout << "Queue is full "<<endl ; 
	 }
 } 
 
 void Enqueue (int value){
 	
 	if (!Fullqueue()){ 
 		rear++;
 		front++ ; 
	 }
	
 }
 
 void display () {
 	for ( int i =1 , i < size , i++ )
 	 cout <<"Elements in Queue: "<<  arr[i];
}

 int Dequeue(){
 	if (!Emptyqueue() || rear == front){
 		front++ ;
	 }
 }
};


int main (){
	Queue A;
	Queue B;  
	Queue C; 
	A.Enqueue(1);
	A.Enqueue(2);
	A.Enqueue(3);
	B.Enqueue(4);
	B.Enqueue(5);  
	
	
	return 0;
	}
