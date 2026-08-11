 #include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void addatend(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            head->next = head; // Circular link
            return;
        }
        Node* current = head;
        while (current->next != head) { // Traverse until last node
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head; // Link to head
    }

    void addatstart(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            head->next = head; // Circular link
            return;
        }
        Node* current = head;
        while (current->next != head) { // Find the last node
            current = current->next;
        }
        newNode->next = head;
        head = newNode;
        current->next = head; // Update the circular link
    }

    void insertatposition(int position, int value) {
        if (position <= 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (position == 1) {
            addatstart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* current = head;
        int count = 1;

        while (count < position - 1 && current->next != head) {
            current = current->next;
            count++;
        }

        if (count < position - 1) {
            cout << "Position out of range" << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void deleteatstart() {
        if (head == NULL) {
            cout << "Nothing to delete" << endl;
            return;
        }
        if (head->next == head) { // Single node in the list
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        while (current->next != head) { // Find the last node
            current = current->next;
        }
        Node* temp = head;
        head = head->next;
        current->next = head; // Update circular link
        delete temp;
    }

    void deleteatend() {
        if (head == NULL) {
            cout << "Nothing to delete" << endl;
            return;
        }
        if (head->next == head) { // Single node in the list
            delete head;
            head = NULL;
            return;
        }
        Node* current = head;
        Node* prev = NULL;
        while (current->next != head) { // Traverse to last node
            prev = current;
            current = current->next;
        }
        prev->next = head; // Update circular link
        delete current;
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

        Node* current = head;
        Node* prev = NULL;
        int count = 1;

        while (current->next != head && count < position) {
            prev = current;
            current = current->next;
            count++;
        }

        if (count < position) {
            cout << "Position out of range" << endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    void displaynodes() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head); // Continue until we loop back to the head
        cout << endl;
    }
};

int main() {
    CircularLinkedList a1;
    int arr[] = {20, 30, 40, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        a1.addatend(arr[i]);
    }
    a1.addatstart(10);
    a1.addatend(80);
    a1.insertatposition(4, 50);
    a1.displaynodes();
    a1.deleteatstart();
    a1.displaynodes();
    a1.deleteatend();
    a1.displaynodes();
    a1.deleteatposition(2);
    a1.displaynodes();

    return 0;
}

