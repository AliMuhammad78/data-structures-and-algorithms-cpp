#include<iostream>
using namespace std;

struct Node {
    string playerName;
    int shirtNo;
    float Avg;
    string role;
    Node* adrs;
};

class LinkedList {
    Node* start, * current, * next;

public:
    LinkedList() {
        start = current = next = NULL; 
    }


    void CreateNode() {
        if (start == NULL) {
            start = new Node;
            cout << "Enter player's name: ";
            cin.ignore();
            getline(cin,start->playerName);
            cout << "Enter shirt number: ";
            cin >> start->shirtNo;
            cout << "Enter role of player: ";
            cin >> start->role;
            cout << "Enter player's average: ";
            cin >> start->Avg;
            cout<<endl;
            start->adrs = NULL; 
            current = start; 
        } else {
        	
            next = new Node;
            cout << "Enter player's name: ";
            cin.ignore();
            getline(cin,next->playerName);
            cout << "Enter shirt number: ";
            cin >> next->shirtNo;
            cout << "Enter role of player: ";
            cin >> next->role;
            cout << "Enter player's average: ";
            cin >> next->Avg;
            cout<<endl;
            next->adrs = NULL; 

            current->adrs = next;
            current = next; 
        }
    }
    

void SearchPlayer() {
    if (start == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    
    int searchChoice;
    cout << "Search by:\n1. Name\n2. Shirt Number\n3. Average\n4. Role\nEnter your choice: ";
    cin >> searchChoice;
    
    current = start;
    string name, role;
    int shirt;
    float avg;
    bool found = false;

    switch (searchChoice) {
        case 1: 
            cout << "Enter player's name: ";
            cin.ignore();
            getline(cin, name);
            while (current != NULL) {
                if (current->playerName == name) {
                    found = true;
                    break;
                }
                current = current->adrs;
            }
            break;
        case 2:
            cout << "Enter shirt number: ";
            cin >> shirt;
            while (current != NULL) {
                if (current->shirtNo == shirt) {
                    found = true;
                    break;
                }
                current = current->adrs;
            }
            break;   
        case 3:
            cout << "Enter player's average: ";
            cin >> avg;
            while (current != NULL) {
                if (current->Avg == avg) {
                    found = true;
                    break;
                }
                current = current->adrs;
            }
            break;    
        case 4:
            cout << "Enter player's role: ";
            cin >> role;
            while (current != NULL) {
                if (current->role == role) {
                    found = true;
                    break;
                }
                current = current->adrs;
            }
            break;   
        default:
            cout << "Invalid choice." << endl;
            return;
    }
    
    if (found) {
        cout << "Player found!" << endl;
        cout << "Player Name: " << current->playerName << endl;
        cout << "Shirt Number: " << current->shirtNo << endl;
        cout << "Role: " << current->role << endl;
        cout << "Average: " << current->Avg << endl;
    } else {
        cout << "Player not found." << endl;
    }
}


void UpdateData(int shirt) {
    if (start == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    current = start;
    bool found = false;

    while (current != NULL) {
        if (current->shirtNo == shirt) {
            found = true;
            break;
        }
        current = current->adrs;
    }

    if (found) {
        int updateChoice;
        cout << "Player found!" << endl;
        cout << "What do you want to update?\n1. Name\n2. Shirt Number\n3. Role\n4. Average\nEnter your choice: ";
        cin >> updateChoice;

        switch (updateChoice) {
            case 1:
                cout << "Enter player's new name: ";
                cin.ignore();
                getline(cin, current->playerName);
                cout << "Player's name updated successfully!" << endl;
                break;

            case 2:
                cout << "Enter new shirt number: ";
                cin >> current->shirtNo;
                cout << "Shirt number updated successfully!" << endl;
                break;

            case 3:
                cout << "Enter new role: ";
                cin >> current->role;
                cout << "Player's role updated successfully!" << endl;
                break;

            case 4:
                cout << "Enter new average: ";
                cin >> current->Avg;
                cout << "Player's average updated successfully!" << endl;
                break;

            default:
                cout << "Invalid choice. No updates made." << endl;
        }
    } else {
        cout << "Player with shirt number " << shirt << " not found." << endl;
    }
}

 
    void DisplayList() {
        if (start == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

         current = start;
         cout<<endl;
        while (current != NULL ) {
            cout << "Player Name: " << current->playerName << endl;
            cout << "Shirt Number: " << current->shirtNo << endl;
            cout << "Role: " << current->role << endl;
            cout << "Average: " << current->Avg << endl;
            cout<<"node address :"<<current<<endl;
            cout<<"Next node address :"<<current->adrs<<endl;
            cout << "--------------------------" << endl;
            current = current->adrs; 
            cout<<endl;
        }
    }
    
    
    void DeletePlayer(int shirtNo) {
        if (start == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = start;
        Node* prev = NULL;
        if (start->shirtNo == shirtNo) {
            start = start->adrs; 
            delete temp; 
            cout << "Player with shirt number " << shirtNo << " deleted." << endl;
            return;
        }

        while (temp != NULL && temp->shirtNo != shirtNo) {
            prev = temp;
            temp = temp->adrs;
        }

        if (temp == NULL) {
            cout << "Player with shirt number " << shirtNo << " not found." << endl;
            return;
        }

        prev->adrs = temp->adrs;
        delete temp; 
        cout << "Player with shirt number " << shirtNo << " deleted." << endl;
    }
    
};



int main() {
    LinkedList L1;
    int choice, shirtNo,num;
    cout<<"Enter the no. of nodes you want to create, only even numbers will be accepted :"<<endl;
    cin>>num;
    if(num%2!=0){
    	cout<<"invalid value entered"<<endl;
	}else{
	    do {
            cout << "\n1. Add Player\n2. Search Player\n3. Update Data\n4. Delete Player by Shirt Number\n5. Display Data\n6. Exit\nEnter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                	for(int i=0;i<num;i++){
                        L1.CreateNode();
                    }
                    break;
                case 2:
                    L1.SearchPlayer();
                    break;
                case 3:
                	cout << "Enter the shirt number of the player to update: ";
                    cin >>shirtNo;
                	L1.UpdateData(shirtNo);
                	break;
                case 4:
                    cout << "Enter shirt number to delete: ";
                    cin >> shirtNo;
                    L1.DeletePlayer(shirtNo);
                    break;
                case 5:
                    L1.DisplayList();
                    break;
                case 6:    
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 6);
   }
}

