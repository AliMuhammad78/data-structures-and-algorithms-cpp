#include <iostream >
using namespace std;


class linkedlist {
	struct Node {
	int data ; 
	Node* next  = NULL; 
	
	
	Node (int value ){
		data = value ; 
		next = NULL ; 
	}
};
  Node* head ; 
  Node* current ; 
  
  public : 
  linkedlist ( ){
  	head = NULL ; 
  	current = NULL ; 
  	
  }
  
  void addatend(int value ){
  	if (head == NULL ){
  		head = new Node (value );
  		return ; 
	  }
	  
	  current = head ; 
	  while ( current -> next != NULL ){
	  	current = current -> next ; 
	  }
	  Node* ptr = new Node (  value );
	current -> next = ptr; 
	ptr -> next = NULL ; 
  }
	
	
	void addatstart (int value ){
		Node * ptr = new Node ( value );
		ptr -> next = head; 
		head = ptr ; 
	}
	
	void insertatposition (int position , int value ){
		current = head; 
		int count ; 
		while ( count < position - 1 ){
			current = current -> next;
			count ++ ; 
		}
		
		Node* ptr = new Node (  value );
		ptr -> next = current -> next ; 
		current -> next = ptr; 
	}
	
	void displaynodes (){
	cout << endl ; 
	current = head; 
	while ( current -> next != NULL ){
		cout << current -> data; 
		cout << " "; 
		current = current -> next; 
}
	
	}
	  
	  
	 void deleteatstart (){
	 	 
	 	Node * ptr = head  ; // pointer ly k head ko uss k brabar kro , head ko agy brha do , pointer ko urra do
	 	head = head -> next ; 
	 	delete ptr ; 
	 }
	
	
	void deleteatend (){   // 2 pointers ko ly k chalo jab current ka next null ho jate to prev k next ko null kr do , current ko urra do 
		if ( head == NULL ){
			cout << " The list is empty , nothing to delete "<<endl;
			return ; 
		}
		if (head -> next == NULL ){
			delete head ; 
			head = NULL ; 
			return ; 
		}
		current = head ;
		Node* prev = NULL ; 
		while ( current -> next != NULL){
			
			prev = current ;  
			current = current -> next ;
		}
		
		 if ( current -> next == NULL ){
		 	
		 	prev -> next = NULL ; 
		 	delete current; 
		 }
	}
	
	
	void deleteatposition ( int position ){
		if (head == NULL ){
			cout << "there is nothing to delete "<< endl ; 
			return; 
		}
		if (position <= 0 ){
			cout << "Invalid position , try again "<< endl; 
			return ; 
		}
		
		if (position == 1 ){
			deleteatstart();
			return ; 
		}
		 
		current = head ; 
		Node* prev = NULL ; 
		int count = 1 ;
		while ( current != NULL && count < position  ){
			prev = current ; 
			current = current-> next  ; 
			count ++;
		}
		
//		if (current == NULL){
//			cout << "position is out of range "<< endl ; 
//			return ;
//		}
	 prev -> next  = current -> next ; 
	 
		delete current ; 
		  
	}
};


int main (){
	linkedlist a1; 
 	 int arr[]= {20 , 30 , 40 , 60 , 70};
 	 int n  = sizeof(arr)/ sizeof (arr[0]);
 	 
 	 for ( int i = 0 ; i < n ; i ++ ){
 	 	a1.addatend(arr[i]);
 	 	
	  }
	  
//	  a1.displaynodes();
	  a1.addatstart(10);
	  a1.addatend(80);
	  a1.insertatposition(4, 50);
	  a1.displaynodes();
	  a1.deleteatstart (); // 10 ko urra dy ga 
	  a1.displaynodes();
	  a1.deleteatend(); // 70 ko urra do 
	  a1.displaynodes(); 
	  a1.deleteatposition(2);
	  a1.displaynodes();
  
  return 0 ;

}
