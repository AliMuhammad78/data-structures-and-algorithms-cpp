 #include <iostream>
using namespace std;

// Definition of a LinkedList class
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;

        // Constructor to initialize a node
        Node(int value) {
            data = value;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;

public:
    // Constructor to initialize an empty linked list
    LinkedList() {
        head = NULL;
         tail = NULL;
    }

    // Destructor to free allocated memory
//    ~LinkedList() {
//        Node* temp;
//        while (head != NULL) {
//            temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }

    // Function to add a node at the end of the list
    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to add a node at the beginning of the list
    void addAtStart(int value) {
        Node* nod = new Node(value);
        nod->next = head;
        head = nod;
        if (tail == NULL) {
            tail = head;
        }
    }

    // Function to print all nodes of the linked list
    void printList() const {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Initialize the linked list with the given values
    int values[] = {19, 26, 31, 12, 14, 98, 91};
    int n = sizeof(values) / sizeof(values[0]);

    LinkedList list;

    // Create the linked list
    for (int i = 0; i < n; i++) {
        list.addNode(values[i]);
    }

    // Print the linked list
    cout << "Original list: ";
    list.printList();

    // Add 72 to the start of the list
    list.addAtStart(72);

    // Print the updated linked list
    cout << "Updated list: ";
    list.printList();

    return 0;
}
//s
