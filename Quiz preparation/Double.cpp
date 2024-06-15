#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:

    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Function to insert a node at the beginning of the list
    void insertFirst(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end of the list
    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to delete a node with a given value
    void deleteNode(int val) {
        Node* current = head;

        while (current) {
            if (current->data == val) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                    if (head) {
                        head->prev = nullptr;
                    }
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                    if (tail) {
                        tail->next = nullptr;
                    }
                }

                delete current;
                return;
            }

            current = current->next;
        }

        cout << "Node with value " << val << " not found." << endl;
    }

    // Function to delete the first node of the list
    void deleteFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
        } else {
            cout << "List is empty. Unable to delete." << endl;
        }
    }

    // Function to delete the last node of the list
    void deleteLast() {
        if (tail) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            delete temp;
        } else {
            cout << "List is empty. Unable to delete." << endl;
        }
    }

    // Function to display the elements of the list
    void displayList() {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoubleLinkedList myList;



    myList.insertLast(7);
    myList.insertLast(8);
    myList.insertLast(6);
    myList.insertLast(7);
    myList.insertLast(8);
    myList.insertLast(6);

    while (true) {
        cout << "Choose an operation:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Delete a node by value" << endl;
        cout << "4. Delete the first node" << endl;
        cout << "5. Delete the last node" << endl;
        cout << "6. Display the list" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                int value1;
                cin >> value1;
                myList.insertFirst(value1);
                break;

            case 2:
                cout << "Enter value to insert at the end: ";
                int value2;
                cin >> value2;
                myList.insertLast(value2);
                break;

            case 3:
                cout << "Enter value to delete: ";
                int value3;
                cin >> value3;
                myList.deleteNode(value3);
                break;

            case 4:
                myList.deleteFirst();
                break;

            case 5:
                myList.deleteLast();
                break;

            case 6:
                myList.displayList();
                break;

            case 7:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
