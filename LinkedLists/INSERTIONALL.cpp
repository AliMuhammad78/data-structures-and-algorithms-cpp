#include <iostream >
using namespace std;

class Linkedlist{
 struct Node {
 	int data ; 
 	Node* next = NULL;
 	
 		Node (int value ){
 		data = value  ; 
 		next = NULL ;
 		
	 }
};
 
 	
 	Node* head  ; 
 	Node* current  ;
	  
 	public :
 		Linkedlist (){
		 head = NULL;
 		current  = NULL ;
 	}

	 
	 void addatend (int value ){
	 	
	 	if (head == NULL ){
	 		head = new Node (value );
	 		return ; 
		 }
		 
		  current = head  ; 
	 	while ( current -> next !=NULL ) {
		 
 
		 current = current -> next ; 
	} 
	
		
		 	Node* ptr = new Node (value ) ;  // ptr k name sy new node 
		  
		 	current -> next = ptr;   
		 	ptr -> next = NULL ;
		 
	 	
	 }
	  
	 void addnodesatstart  (int value ){ 
	 Node* nod = new Node(value ) ;

	 nod -> next = head ; 
	 head = nod ; 
	 	
	 }
	 
	 

	 void displaynodes ( ){
	 	current = head  ;
	  while ( current  != NULL ) { 
     
  
	 cout << current -> data ;
	 cout << " " ; 
	 current = current -> next ; 
	  
	 }
	   
	 }
 	 
 	 void insertatposition(int position , int value ){
 	current = head; 
 	int count  = 1 ; 
 	while (  count < position - 1  ){
 		current = current -> next ; 
 		count ++; 
}
	  
	      Node* ptr = new Node (value );
	      ptr -> next = current -> next ; 
	      current -> next = ptr;
		     
	      
	  
}
 	 }; 
 
 int main (){
 	Linkedlist a1; 
 	 int arr[]= {20 , 30 , 40 , 60 , 70};
 	 int n  = sizeof(arr)/ sizeof (arr[0]);
 	 
 	 for ( int i = 0 ; i < n ; i ++ ){
 	 	a1.addatend(arr[i]);
 	 	
	  }
	  
//	  a1.displaynodes();
	  a1.addnodesatstart(10);
	  a1.addatend(80);
	  a1.insertatposition(4, 50);
	  a1.displaynodes();
	  
  
  return 0 ;

 	}

