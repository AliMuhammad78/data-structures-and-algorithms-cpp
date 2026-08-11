#include <iostream>
using namespace std; 

struct Node {
	int data ; 
	Node* next ; 
	
};
class linkedlist {
	public: 
//	 Node* next ; 
//	 int data ;  
Node* head ; 
Node* current ; 
Node* next ; 
 
	
	linkedlist (  int data ){
		head -> data = data ; 
		head -> next = NULL; 
	}
};
//void displaynodes (Node* &head ){
 
	
	
	
	
	
//	cout << start  -> data<< endl  ; 
//	cout <<start -> next<< endl ; 
//}
void insertatHead (Node* &head , int d ){ //address of head is passed by reference , and d is the data of newly created node 
	// first create a node that you want to add , 
	Node* temp = new Node ; // temp name ki new node bnai 
	
//	temp -> data = d ; 

 temp -> next = head ; 
 head = temp ; 
	
}



int main (){
 Node * ndode1 = new Node (83);
 cout << node1 -> data << endl; 
 cout << node1-> next << endl ; 
 
}




