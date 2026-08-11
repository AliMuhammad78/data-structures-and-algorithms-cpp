				// Double Linked List 
#include <iostream>
using namespace std ; 


	struct Node {
		int data ; 
	
		Node * next ;
		Node * prev ;  
		
		Node ( int value  ) {
			data = value ; 
			next = NULL ; 
			prev = NULL ;
		}		
	};

class linkedlist {
	

	Node * head ; 
	Node * current ; 
 
	
	public : 
	linkedlist (){
		head = current   = NULL ;
		
	}
	void addatend(int value  ){
		if ( head == NULL ){
			head = new Node ( value );
			return  ;
		}
	 current = head ; 
	 while ( current -> next != NULL){
	 	current = current -> next ;
	 }
		Node* nod = new Node(value );
		current -> next = nod ; 
 
		nod-> prev = current ; 
	}
	
	
	void addatstart (int value ){
		Node* nod =  new Node (value );
		nod -> next = head ; 
	 if (head != NULL) {
        head->prev = nod;
    }
    head = nod;
	}
	
 
	
	void insertatposition ( int position , int value ){
		int count = 0 ; 
		current  = head ; 
		while (count != position -1 ){
			current = current -> next ; 
			count ++ ; 
		} 
		
		Node * nod = new Node (value );
	 nod -> next = current -> next ;
	 current -> next = nod ;  
	 nod -> prev = current  ; 
	  
}


deleteatstart(){
	if ( head == NULL ){
		cout << "Nothing to delete "<< endl ;
	}
	
	current = head ;
	head = head -> next ; 
	head -> prev = NULL ; 
	delete current ; 
	
}


void deleteatend (){
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
		while ( current-> next != NULL ){
			current = current -> next ; 
		}
		current -> prev-> next = NULL; 
		delete current ; 
		
}
	
	

void deleteatposition(int position) {
    if (head == NULL) {
        cout << "Nothing to delete" << endl;
        return;
    }
    if (position <= 0) {
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 1) {
        deleteatstart();
        return;
    }

    current = head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        cout << "Position out of range" << endl;
        return;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    delete current;
}

	
	void displaynodes ( ){
		cout << endl ;
		current = head ; 
		while ( current != NULL ){
			cout << current -> data << " " ;
			current = current -> next; 
		}
	}
	
	
};


int  main (){
	linkedlist a1;
	int arr[]= {20 , 30 , 40 , 60 , 70};
 	 int n  = sizeof(arr)/ sizeof (arr[0]);
 	 
 	 for ( int i = 0 ; i < n ; i ++ ){
 	 	a1.addatend(arr[i]);
 	 }
 	 	 a1.addatstart(10);
	  a1.addatend(80);
	  a1.insertatposition(4, 50);
	  a1.displaynodes();
	  a1.deleteatstart (); 
	  a1.displaynodes();
	  a1.deleteatend();  
	  a1.displaynodes(); 
	  a1.deleteatposition(2);
	  a1.displaynodes();
  
  return 0 ;
	
}
