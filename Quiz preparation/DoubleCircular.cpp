#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoubleCircularLinkedList {
private:
    Node* head;

public:
    DoubleCircularLinkedList() {
        head = nullptr;
    }

    void insertAtFirst(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* current = head;
        do {
            if (current->data == value) {
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == head) {
                    head = current->next;
                }

                delete current;
                cout << "Node with value " << value << " deleted successfully." << endl;
                return;
            }

            current = current->next;
        } while (current != head);

        cout << "Node with value " << value << " not found." << endl;
    }

    void deleteFirstNode() {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;

        delete temp;
        cout << "First node deleted successfully." << endl;
    }

    void deleteLastNode() {
        if (!head) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        Node* temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;

        delete temp;
        cout << "Last node deleted successfully." << endl;
    }

    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);

        cout << endl;
    }
};

int main() {
    DoubleCircularLinkedList doubleCircularList;

    int choice, value;

    doubleCircularList.insertAtLast(7);
    doubleCircularList.insertAtLast(8);
    doubleCircularList.insertAtLast(6);
    doubleCircularList.insertAtLast(7);
    doubleCircularList.insertAtLast(8);
    doubleCircularList.insertAtLast(6);

    do {
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete a node\n";
        cout << "4. Delete the first node\n";
        cout << "5. Delete the last node\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                doubleCircularList.insertAtFirst(value);
                break;

            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                doubleCircularList.insertAtLast(value);
                break;

            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                doubleCircularList.deleteNode(value);
                break;

            case 4:
                doubleCircularList.deleteFirstNode();
                break;

            case 5:
                doubleCircularList.deleteLastNode();
                break;

            case 6:
                cout << "List elements: ";
                doubleCircularList.display();
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
