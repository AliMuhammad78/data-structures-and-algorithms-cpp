// Linked list functions 
#include <iostream>
using namespace std;


struct Node {
	string name; 
	int phoneNo;
	string email; 
	Node* next ;
	
};

class LinkedList{
	Node *start , *current , * next ; 
	
	public:
	LinkedList (){
	
	 start = current = next = NULL;
}
	void AddContact(){
		if (start == NULL ){
		start = new Node ;
		cout <<" Enter name : ";
		cin >> start -> name ; 
		cout << " Enter Phone number : ";
		cin >> start -> phoneNo; 
		cout << " Enter email address : ";
		cin >> start -> email; 
		start -> next = NULL ; 
		current = start ; 	
	  } else {
		next = new Node ;
		cout <<" Enter name : ";
		cin >> next -> name ; 
		cout << " Enter Phone number : ";
		cin >> next -> phoneNo; 
		cout << " Enter email address : ";
		cin >> next -> email; 
		next -> next = NULL ; 
		current -> next = next ;
		 current = next ; 
}
}
	void SearchContact(){
		if ( start == NULL ){
			cout << " Contact list is empty "<< endl;
			return ;
		}
		string searchName ;
		cout << "Enter the name to search :";
		cin >> searchName;
		
		
	current = start ;
	bool found = false ; 
	
	while ( current != NULL ){
		if (current-> name == searchName ){
			found = true ; 
			break ; 
		}
		current = current -> next ; 
	}
	
	if (found ){
		cout << "Contact found : "<< endl ;
		cout << "Contact name : "<< current -> name << endl ;
		 cout << "Contact phone number is "<< current -> phoneNo << endl ; 
		 cout << "Contact's email address is : "<< current -> email << endl ; 
		 }else { 
		 cout << "contact not found "<< endl ; 
		 }
	}

	
	
	
	void UpdateContact(string  searchName ){
		if (start ==NULL ){
			cout << " Contact list is empty ";
		return  ;
		}
		
		current = start ; 
		bool found = false ; 
		while (current != NULL ){
			if (current -> name == searchName ){
				found = true; 
			 break  ; 
			}	
			current =current -> next ; 
		}
		if (found ){
			int updateChoice ; 
			cout << "Contact found"<<endl; 
			cout << " What do you want to update?\n1. name\n2. phone number\n3. email address\nEnter your choice ";
			cin >> updateChoice; 
			
			switch  (updateChoice ){
				case 1:
					cout << "Enter new name :";
					cin >> current -> name ; 
					cout << "Name updated successfully ."<< endl;
					break ; 
					
				case 2: 
				    cout << "Enter new phone number : ";
				    cin >> current -> phoneNo; 
				    cout << " Phone number updated successfully "<<endl ; 
				    break ; 
				 
				case 3: 
				    cout << "Enter new email address: ";
				    cin >> current -> email; 
				    cout << "Email address updated successfully . "<< endl ; 
				    break;
				   
				 default :
				 cout << "Invalid Entery . No update is made . ";
				   
				
				 
				
			}
		}else { 
		     cout << "Contact not found "<<endl; 
		}
		
	}
	void DisplayContacts(){
		if (start == NULL ){
			cout << "The contact list is empty . Nothing to display "<<endl; 
			return ;
		}
		current = start;
		cout <<endl<< "Contact List : "<<endl; 
		while (current != NULL){
			cout << "Name : " << current -> name << endl ;
			 cout << "Phone number: "<< current -> phoneNo << endl;
			  cout << "Email :" << current -> email << endl;
			  cout <<"------------------" <<endl; 
			  current = current -> next; 
		}
	}
	
};




int main (){
	LinkedList contactList ; 
	int choice; 
	string searchName ; 
	int numContacts ; 
	
	cout << " Enter the number of contacts you want to add . Contacts should be even in number "<<endl; 
	cin >> numContacts ; 
	
	if (numContacts % 2 != 0 ){
		cout << "Error: You must enter even number of contacts to add"<<endl; 
		return 1; 
	}
	
	for (int i = 0 ; i < numContacts ; i++ ){
		contactList.AddContact();
	}
	
	
	do {
		
		cout <<" \n1. Searchcontact \n2.Update contact \n3.Display contact \n4.Exit"<<endl ; 
		cin >> choice ;
		switch (choice){
		 
			case 1: 
				contactList.SearchContact();
				break; 
				
			case 2: 
			cout << "Enter the name of contact to update ";
			cin.ignore();
			getline(cin , searchName);
			    contactList.UpdateContact(searchName);
				break;
				
			case 3: 
				contactList.DisplayContacts();
				break; 
				
			case 4: 
				 cout << "Exiting...."	<<endl;
				 break; 
				 
			default : 
			cout << "Invalid choice "	<< endl;	 
				
		}
		
	} while (choice != 4);
	
	return 0;
	} 
