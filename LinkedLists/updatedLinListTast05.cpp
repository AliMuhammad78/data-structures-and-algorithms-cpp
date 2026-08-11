 #include<iostream>
using namespace std;

struct Node {
    string name;        
    string phoneNo;  
    string email;      
    Node* next;        
};

class LinkedList {
    Node* start, * current, * next;

public:
    LinkedList() {
        start = current = next = NULL;
    }

     
    void AddContact() {
        if (start == NULL) {
            start = new Node;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, start->name);
            cout << "Enter phone number: ";
            cin >> start->phoneNo;
            cout << "Enter email: ";
            cin >> start->email;
            start->next = NULL;
            current = start;
        } else {
            next = new Node;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, next->name);
            cout << "Enter phone number: ";
            cin >> next->phoneNo;
            cout << "Enter email: ";
            cin >> next->email;
            next->next = NULL;

            current->next = next;
            current = next;
        }
    }

    
    void SearchContact() {
        if (start == NULL) {
            cout << "The contact list is empty." << endl;
            return;
        }

        string searchName;
        cout << "Enter name to search: ";
        cin.ignore();
        getline(cin, searchName);

        current = start; // current to start k brabar iss liye kiya ha ta k hamari searching pehli node sy shoro ho 
        bool found = false; // jaan booj ker found variable ko false kiya ha , ye tab true ho ga jab current name = searchName 

        while (current != NULL) { 
            if (current->name == searchName) {
                found = true;
                break;
            }
            current = current->next;
        }

        if (found) {
            cout << "Contact found!" << endl;
            cout << "Name: " << current->name << endl;
            cout << "Phone Number: " << current->phoneNo << endl;
            cout << "Email: " << current->email << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    
    void UpdateContact(string searchName) {
        if (start == NULL) {
            cout << "The contact list is empty." << endl;
            return;
        }

        current = start;
        bool found = false;

        while (current != NULL) {
            if (current->name == searchName) {
                found = true;
                break;
            }
            current = current->next;
        }

        if (found) {
            int updateChoice;
            cout << "Contact found!" << endl;
            cout << "What do you want to update?\n1. Name\n2. Phone Number\n3. Email\nEnter your choice: ";
            cin >> updateChoice;

            switch (updateChoice) {
                case 1:
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, current->name);
                    cout << "Name updated successfully!" << endl;
                    break;

                case 2:
                    cout << "Enter new phone number: ";
                    cin >> current->phoneNo;
                    cout << "Phone number updated successfully!" << endl;
                    break;

                case 3:
                    cout << "Enter new email: ";
                    cin >> current->email;
                    cout << "Email updated successfully!" << endl;
                    break;

                default:
                    cout << "Invalid choice. No updates made." << endl;
            }
        } else {
            cout << "Contact not found." << endl;
        }
    }

     
    void DisplayContacts() {
        if (start == NULL) {
            cout << "The contact list is empty." << endl;
            return;
        }

        current = start;
        cout << endl << "Contact List:" << endl;
        while (current != NULL) {
            cout << "Name: " << current->name << endl;
            cout << "Phone Number: " << current->phoneNo << endl;
            cout << "Email: " << current->email << endl;
            cout << "--------------------------" << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList contactList;
    int choice;
    string searchName;
    int numContacts;

   
    cout << "Enter the number of contacts you want to add (must be an even number): ";
    cin >> numContacts;

    
    if (numContacts % 2 != 0) {
        cout << "Error: You must enter an even number of contacts." << endl;
        return 1;  // Exit if the number is odd
    }

    
    for (int i = 0; i < numContacts; i++) {
        contactList.AddContact();
    }

    do {
        cout << "\n1. Search Contact\n2. Update Contact\n3. Display All Contacts\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                contactList.SearchContact();
                break;

            case 2:
                cout << "Enter the name of the contact to update: ";
                cin.ignore();
                getline(cin, searchName);
                contactList.UpdateContact(searchName);
                break;

            case 3:
                contactList.DisplayContacts();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

