#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtFirst(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
        }
    }

    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }

    void insert(int value) {
        
        insertAtLast(value);
    }

    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head->next;
        Node* previous = head;

        // Search for the node to delete
        while (current != head && current->data != value) {
            previous = current;
            current = current->next;
        }

        if (current == head && current->data != value) {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        previous->next = current->next;

        if (current == head) {
            head = previous;
        }

        delete current;
        cout << "Node with value " << value << " deleted successfully." << endl;
    }

    void deleteFirstNode() {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head->next;
        head->next = temp->next;

        if (temp == head) {
            head = nullptr;
        }

        delete temp;
        cout << "First node deleted successfully." << endl;
    }

    void deleteLastNode() {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head->next;
        Node* previous = head;

        // Traverse to the last node
        while (current->next != head) {
            previous = current;
            current = current->next;
        }

        previous->next = head;

        if (current == head) {
            head = nullptr;
        }

        delete current;
        cout << "Last node deleted successfully." << endl;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head->next;

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList circularList;

    int choice, value;

    circularList.insertAtLast(7);
    circularList.insertAtLast(8);
    circularList.insertAtLast(6);
    circularList.insertAtLast(7);
    circularList.insertAtLast(8);
    circularList.insertAtLast(6);

    do {
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert a node (Simple)\n";  
        cout << "4. Delete a node\n";
        cout << "5. Delete the first node\n";
        cout << "6. Delete the last node\n";
        cout << "7. Display\n";  
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                circularList.insertAtFirst(value);
                break;

            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                circularList.insertAtLast(value);
                break;

            case 3:
                cout << "Enter value to insert at the end (alternative): ";
                cin >> value;
                circularList.insert(value);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                circularList.deleteNode(value);
                break;

            case 5:
                circularList.deleteFirstNode();
                break;

            case 6:
                circularList.deleteLastNode();
                break;

            case 7:
                cout << "List elements: ";
                circularList.display();
                break;

            case 0:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);

    return 0;
}
