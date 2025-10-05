#include <iostream>
#include <cstddef>   
using namespace std;

// -------------------- NODE STRUCTURE --------------------
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

// -------------------- DOUBLY LINKED LIST CLASS --------------------
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(NULL), tail(NULL) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Node " << val << " inserted at the end.\n";
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Node " << val << " inserted at the beginning.\n";
    }

    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->data != val) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Node with value " << val << " not found.\n";
            return;
        }

        if (head == tail && temp == head) {
            head = tail = NULL;
        }
        else if (temp == head) {
            head = head->next;
            if (head) head->prev = NULL;
        }
        else if (temp == tail) {
            tail = tail->prev;
            if (tail) tail->next = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Node with value " << val << " deleted.\n";
    }

    void displayForward() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Forward Traversal: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (tail == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = tail;
        cout << "Backward Traversal: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// -------------------- MAIN PROGRAM --------------------
int main() {
    DoublyLinkedList list;
    int choice, val;

    do {
        cout << "\nDOUBLY LINKED LIST MENU\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete a node\n";
        cout << "4. Display forward\n";
        cout << "5. Display backward\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            case 4:
                list.displayForward();
                break;
            case 5:
                list.displayBackward();
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
