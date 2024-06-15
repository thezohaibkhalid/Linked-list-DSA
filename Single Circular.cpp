#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SingleCircularLinkedList {
private:
    Node* head;

public:
    SingleCircularLinkedList() {
        head = nullptr;
    }

    // Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            newNode->next = head->next;
            head->next = newNode;
            head = newNode;
        }
    }

    // Insert at Position
    void insertAtPosition(int value, int position) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < position - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete from End
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        if (temp == head) {
            delete head;
            head = nullptr;
        } else {
            Node* toDelete = temp->next;
            temp->next = head->next;
            delete toDelete;
        }
    }

    // Display
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head->next);

        cout << endl;
    }
};