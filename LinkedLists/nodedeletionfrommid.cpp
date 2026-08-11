 #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to delete the middle node
    void deleteMiddle() {
        if (head == NULL || head->next == NULL) {
            cout << "List is too short to delete the middle element." << endl;
            return;
        }

        Node *slow = head, *fast = head;
        Node *prev = NULL;

        // Move fast pointer by two steps and slow by one
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Now slow is at the middle node
        prev->next = slow->next;
        delete slow;

        cout << "Middle node deleted." << endl;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Adding nodes to the linked list
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Original list:" << endl;
    list.display();

    // Deleting the middle node
    list.deleteMiddle();

    cout << "List after deleting the middle node:" << endl;
    list.display();

    return 0;
}

