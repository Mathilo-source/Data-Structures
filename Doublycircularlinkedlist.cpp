#include <iostream>
using namespace std;

// -------------------- NODE STRUCTURE --------------------
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

// -------------------- DOUBLY CIRCULAR LINKED LIST CLASS --------------------
class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() : head(NULL) {}

    // Insert at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev; // last node
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "Node " << val << " inserted at the end.\n";
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Node " << val << " inserted at the beginning.\n";
    }

    // Delete a node by value
    void deleteNode(int val) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prevNode = NULL;

        // Search for the node
        do {
            if (temp->data == val) break;
            prevNode = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->data != val) {
            cout << "Node with value " << val << " not found.\n";
            return;
        }

        // Only one node
        if (temp->next == head && temp->prev == head) {
            delete temp;
            head = NULL;
        }
        // Deleting the head node
        else if (temp == head) {
            Node* tail = head->prev;
            head = head->next;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
        // Deleting in between or end
        else {
            Node* tail = head->prev;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            if (temp == tail) {
                // If it was the last node, adjust tail links
                head->prev = temp->prev;
            }
            delete temp;
        }
        cout << "Node with value " << val << " deleted.\n";
    }

    // Display forward
    void displayForward() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Forward traversal: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Display backward
    void displayBackward() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* tail = head->prev;
        Node* temp = tail;
        cout << "Backward traversal: ";
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != tail);
        cout << endl;
    }
};

// -------------------- MAIN PROGRAM --------------------
int main() {
    DoublyCircularLinkedList list;
    int choice, val;

    do {
        cout << "\n====== DOUBLY CIRCULAR LINKED LIST MENU ======\n";
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
