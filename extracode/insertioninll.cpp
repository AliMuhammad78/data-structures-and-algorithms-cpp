 #include <iostream > 
 using namespace std; 
 
 
 class linkedlist {
 	
 	struct Node {
 		
 		int data ; 
 		Node * next  ; 
 		
 		Node ( int value ){
 			data = value ; 
 			next = NULL ; 
		 }
	 };
	 Node* head ; 
	 Node * current ; 
	 public:
	 linkedlist (){
	 	head = NULL; 
	 	current = NULL ; 
	 }
	 
	 void insertatend (int value ){
	 	if (head== NULL ){
	 		head = new Node( value );
	 		return ; 
		 }
		 
		current = head ; 
		while ( current -> next != NULL ){
			current = current ->next ;  
		}
	 	
	 	Node * ptr = new Node ( value);
	 	current -> next = ptr ; 
	 	ptr -> next = NULL ; 
	 	
	 }
	 
	 void insertatstart (int value ){
	 	 
		 
		 Node * ptr  = new Node( value);
		 ptr -> next = head ; 
		 head = ptr ; 
		 
	 }
	 
	 
	 void insertatposition (int position , int value ){
	 	current = head ; 
	 	int count = 1; 
	 	while ( count < position - 1 ){
	 		current = current -> next ; 
	 		
		 }
	 	Node * ptr = new Node ( value );
	  ptr -> next = current->next  ;
	  current -> next = ptr ;
	 	
	 	
	 }
	 
	 void displaynodes (){
	 	current = head ; 
	 	while ( current-> next != NULL ){
	cout << current -> data<< endl ; 
	 current = current -> next ; 
	 }
	 
	 	 }
	 
	 
	 
 };
 
 
 int main (){
 	
 	linkedlist a1 ; 
 	
 	int arr [] = {13, 19, 282, 9 };
 	int size = sizeof(arr)/ sizeof(arr[0]);
 	
 	for (int i = 0 ; i <size ; i++ ){
 		a1.insertatend(arr[i]);
	 }
 	
 	
 	
 	
 	a1.insertatend(4);
 	a1.displaynodes();
 }
