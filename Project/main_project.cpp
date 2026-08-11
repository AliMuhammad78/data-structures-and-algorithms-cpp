#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <conio.h>
#include <vector>
#include <windows.h>
using namespace std;

stack <string> bookstack ; 

void Intropage(){
	char name[15]={'O','l','d',' ','B','o','o','k',' ','C','o','r','n','e','r' };
	cout<<"\n\n\n\n\t\t\t\t\t";
	for(int i=0;i<35;i++){
		cout<<"-";
		Sleep(20);
	}
	
	cout<<endl;
	cout<<"\t\t\t\t    ||     ";
	
	for(int i=0;i<15;i++){
		cout<<name[i];
		Sleep(100);
	}
	cout<<" \t\t||";
	cout<<endl;
	cout<<"\t\t\t\t\t";
	for(int i=0;i<35;i++){
		cout<<"-";
		Sleep(20);
	}
	
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\tMade By : MUHAMMAD ALI SAAGAR "<<endl;
	cout<<"\t\t\t\t\tRoll Number  : 23021519-095 "<<endl;
	cout<<"\t\t\t\t\tSection  : BsCS-C "<<endl;
	Sleep(3000);                                                     // pause for 4sec 
	system("cls");
}



struct Book {
    int id;
    string title;
    string author;
    double price;
    Book* next;

     
    Book(int bookId, string bookTitle, string bookAuthor, double bookPrice) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        price = bookPrice;
        next = NULL;
    }
};

 
class BookManager {
private:
    Book* head; 
    vector<Book> bookArray;

public:
     
    BookManager() {
        head = NULL;
    }

     void addBook(int id, string title, string author, double price) {
     	
        Book* newBook = new Book(id, title, author, price);  // basically addition is at the start 
        newBook->next = head;
        head = newBook;
         bookArray.push_back(*newBook);
         
        cout << "Book added successfully!"<< endl;
       
        Sleep(2000); 
        
        system("cls");
         
    }

  
    void removeBook(int id) {   // book will be removed based on ID of book 
        Book* current = head;
        Book* previous = NULL;

        while (current != NULL && current->id != id) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Book not found."<< endl;
            Sleep(2000);
            system("cls");
            return;
        }

        if (previous == NULL) { // if id is found at first position , then head will be moved forward, 1st node will be deleted
            head = current->next;
        } else {               // if not at first position 
            previous->next = current->next; 
        }

        delete current;
        cout << "Book removed successfully!"<< endl;
        Sleep(2000);
        system("cls");
    }

    
    void updateBook(int id, string title, string author, double price) {
        Book* current = head;
        while (current != NULL) {
            if (current->id == id) {
                current->title = title;
                current->author = author;
                current->price = price;
                cout << "Book updated successfully!"<<endl;
                Sleep(2000);
                system("cls");
                return;
            }
            current = current->next;
        }
		cout << "Book not found. Enter the book first to exchange "<< endl;
	     	Sleep(2000);
		    system("cls");
    }

     void searchBooks(string title) {
        Book* current = head;
        bool found = false;

        while (current != NULL) {
            if (current->title.find(title) != string::npos) { // find() give the first index of the list .
            												// if there is nothing , it would give npos , noposition
                cout << " ID: " << current->id <<endl;
				 cout << " Title: " << current->title <<endl;
				 cout << " Author: " << current->author <<endl;
				 cout << " Price: " << current->price << endl ;
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << "No books found with the title: " << title << endl;
        }
               Sleep(2000);
               system("cls");
    }

     void displayBooks() {
        Book* current = head;

        if (current == NULL) {
            cout << "No books available."<< endl;
            Sleep(2000);
            system("cls");
            return;
         }
         cout << "Total available books : " << bookArray.size() << endl;
         
        while (current != NULL) {
             cout << " ID: " << current->id <<endl;
		     cout << " Title: " << current->title <<endl;
			 cout << " Author: " << current->author<<endl;
			 cout << " Price: " << current->price << endl;
			 cout << "------------------------"<< endl; 
             current = current->next;
        }
		    Sleep(4000);
            system("cls");
    }

     
    void buyBook(string title) {
        Book* current = head;
        while (current != NULL) {
            if (current->title == title) {
                cout << "The title of book you bought :" << current->title <<endl;
				cout<< " Author name : " << current->author <<endl;
				cout<< " You bought the book in Rs." << current->price  <<endl;
                Sleep(3000);
        		system("cls");
				return;
            }
            current = current->next;
        }
        cout << "Book not found."<<endl;
        		Sleep(2000);
        		system("cls");
    }

     void sellBook(string title) {
        Book* current = head;
        while (current != NULL) {
            if (current->title == title) {
                cout << " The title of book you sold : " << current->title <<endl;
				cout  << " Name of author  " << current->author<<endl;
				cout  << " You sold the book by Rs." << current->price << endl;
                Sleep(3000);
        		system("cls");
				return;
            }
            current = current->next;
        }
        		cout << " Book not found. Enter the book first to sell "<<endl;
        		Sleep(2000);
        		system("cls");
    }

     void exchangeBook(string title) {
    	int prc; 
        Book* current = head;
        while (current != NULL) {
            if (current->title == title) {
            	cout << " Enter your books details please\n1.ID of your book "<< endl ;
            	cin >> current -> id ; 
            	cin.ignore();
            	cout << "2.title of your book "<< endl; 
            	cin >> current -> title ; 
            	cin.ignore();
            	cout << "3.author name "<< endl; 
            	cin >> current -> author; 
            	cin.ignore();
            	cout << "Enter your price "<< endl; 
            	cin >> prc; 
            	if (prc == current-> price ){
				
            	
				 
                cout << "You exchanged: " << current->title << " by " << current->author << " with your book "<<endl;
                	Sleep(3000);
        			system("cls");
          }
                else { 
                cout << "Your price could not match with previous book"<< endl;
				}
				Sleep(2000);
        		system("cls");
				return;
            
            }
            current = current->next;
        }
        cout << "Book not found."<<endl;
        		Sleep(2000);
        		system("cls");
    }
};



 string getAlphasOnly(int length)
{
	string Buffer = "";
	char tempCh;
	int i = 0;

	while (i < length)
	{
		tempCh = _getch();
		if ((tempCh >= 'A' && tempCh <= 'Z') || (tempCh >= 'a' && tempCh <= 'z'))
		{
			cout << tempCh;
			Buffer.push_back(tempCh);
			i++;
		}
		else if (tempCh == '\b' && i > 0)
		{
			cout << "\b \b";
			Buffer.erase(Buffer.size() - 1);
			i--;
		}
		else if (tempCh == '\r' && i > 0)
		{

			break;
		}
	}
	cout << endl;
	return Buffer;
}


 void adminMenu(BookManager& manager) {
    int choice;
    do {
        cout<<"\t\t============================================"<<endl;
	            cout<<"\t\t|          Admin Menu             |"<<endl;
	            cout<<"\t\t============================================"<<endl;  

        cout << "Enter 1 to Add Book"<< endl ;
        cout << "Enter 2 to Remove previously added Book"<< endl ;
        cout << "Enter 3 to Update Book details "<< endl ;
        cout << "Enter 4 to View All Books"<< endl ;
        cout << "Enter 5 to go Back to Main Menu"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()){ 
		cin.clear();
		cout << "\n\t\t\t\t\t\t Please enter some number" << endl; 
		cin.ignore();
	}else{

        switch (choice) {
        case 1: {
        	 system("cls");
        	 string title, author;
            double price;
            int id;
           try {
		
            cout << " Enter Book ID: ";
            cin >> id;
            if (cin.fail()){
			
		throw (id );
		}
	}
        catch (...) {
		cout << "Please enter the id in integers " << endl ; 
             
            system ("pause ");
           break ; 
           }
           cin.ignore();
           
		    cout << " Enter Book Title: ";
		    
		    title = getAlphasOnly (100);

            cout << " Enter Book Author: ";
            
            author  = getAlphasOnly (100 );


            cout << " Enter Book Price: ";
             
            cin >> price;

            manager.addBook(id, title, author, price);

           break  ; 
        }
        case 2: {
        	system("cls");
            int id;
            cout << "Enter Book ID to remove: ";
            cin >> id;
            manager.removeBook(id);
            break;
        }
        case 3: {
        	system("cls");
            int id;
            string title, author;
            double price;

            cout << " Enter Book ID to update: ";
            cin >> id;
            cin.ignore();
            cout << " Enter new Book Title: ";
            title = getAlphasOnly (100 );

            cout << " Enter new Book Author: ";
            author  = getAlphasOnly (100 );
 
            cout << " Enter new Book Price: ";
            cin >> price;

            manager.updateBook(id, title, author, price);
            break;
        }
        case 4:{

		 system ("cls");
            manager.displayBooks();
            break;
        }
	    	
      case 5 : {
      	
      	system ("cls");
      	bookstack.pop();
		break;
	  }
        default:
        	cout << "Invalid choice . Enter some number again "<< endl ; 
 
        }
	}
 } while (choice != 5);
    
}


 void userMenu(BookManager& manager) {
    int choice;
    do {
         cout<<"\t\t============================================"<<endl;
	            cout<<"\t\t|          User Menu             |"<<endl;
	            cout<<"\t\t============================================"<<endl;
        cout << "Press 1 to Add Book"<< endl ;
        cout << "Press 2 to Search Books"<< endl ;
        cout << "Press 3 to View All Books"<< endl ;
        cout << "Press 4 to Buy Book"<< endl ;
        cout << "Press 5 to Sell Book"<< endl ;
        cout << "Press 6 to Exchange Book"<< endl ;
        cout << "Press 7 to Back to Main Menu"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;
if (cin.fail()){ 
		cin.clear();
		cout << "\n\t\t\t\t\t\t Please enter some number" << endl; 
		cin.ignore();
	}else{

        switch (choice) {
        case 1: {
        	 system("cls");
        	 string title, author;
            double price;
            int id;
           try {
		   
            

            cout << " Enter Book ID: ";
            cin >> id;
            if (cin.fail()){
			
		throw (id );
		}
	}
        catch (...) {
		cout << "Please enter the id in integers " << endl ; 
            
            system ("pause ");
           break ; 
           }
           cin.ignore();
           
		    cout << " Enter Book Title: ";
		    title = getAlphasOnly (100 );

            cout << " Enter Book Author: ";
            author  = getAlphasOnly (100 );
 
            cout << " Enter Book Price: ";
             
            cin >> price;

            manager.addBook(id, title, author, price);

           break ; 
        }

        case 2: {
        	system("cls");
            string title;
            cin.ignore();
            cout << "Enter Book Title to search: ";
            title = getAlphasOnly (100 );
 
            manager.searchBooks(title);
            break;
        }
        case 3:{
			
		system("cls");
            manager.displayBooks();
            break;
        }
        case 4: {
        	system("cls");
            string  title;
            cout << "Enter Book title to buy: ";
            title = getAlphasOnly (100 );
 
            manager.buyBook(title);
            break;
        }
        case 5: {
        	system("cls");
            string title;
            cout << " Enter Book title  to sell: ";
            title = getAlphasOnly (100 );
 
            manager.sellBook(title);
            break;
        }
        case 6: {
        	system("cls");
            string title ;
             cout << " Enter Book title  to exchange : ";
             title = getAlphasOnly (100 );

            manager.exchangeBook(title);
            break;
        }
        case 7: {
        	system ("cls ");
        	bookstack.pop();
			break;
		}
        default :{
			  	cout << "Invalid choice . Enter some number again "<< endl ; 
		}
  }
   }
    } while (choice != 7);
}

 void mainmenu (BookManager& manager){ 
 int choice;
     Intropage ();
    do {
        cout<<"\n\n\n\n\t\t\t\t\t\t MAIN MENU  "<<endl;
		cout<<"\n\n\t\t\t\t\t\t 1. Admin Menu  "<<endl;
		cout<<"\t\t\t\t\t\t 2. User Menu "<<endl;
		cout<<"\t\t\t\t\t\t 3. Exit "<<endl;
		cout<<"\n\n\n\t\t\t\t\t\t Enter your choice :";
		cin>>choice;
		if (cin.fail()){
		cin.clear();
		cout << "\n\t\t\t\t\t\t Please enter some number" << endl; 
		cin.ignore();
	}else{

        switch (choice) {
        case 1:
        	bookstack.push("mainmenu");
        	system("cls");
            adminMenu(manager);
            break;
        case 2:
        	bookstack.push("mainmenu");
        	system("cls");
            userMenu(manager);
            break;
        case 3:
            cout << "Exiting... See you again "<< endl;
            break;
        default:
            cout << "Invalid choice! Please try again."<< endl ;
        }
   }
 } while (choice != 3);

 	
 }
 
 
 
int main() {
    BookManager manager;
    mainmenu(manager);


    return 0;
}

