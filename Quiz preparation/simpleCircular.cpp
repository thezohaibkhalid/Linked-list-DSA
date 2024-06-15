#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void linkedListTraversal(Node* head) {
    Node* ptr = head;
    do {
        cout << "Element is " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

Node* insertAtFirst(Node* head, int data) {
    Node* ptr = new Node;
    ptr->data = data;

    Node* p = head->next;
    while (p->next != head) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

Node* deleteNode(Node* head, int key) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return nullptr;
    }

    Node* temp = head;
    Node* prev = nullptr;
    // If the node to be deleted is the first node
    if (temp->data == key) {
        prev = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        if (head == head->next) {
            delete head;
            return nullptr;
        }
        temp->next = head->next;
        head = head->next;
        delete prev;
    } else {
        prev = temp;
        temp = temp->next;
        while (temp != head && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head) {
            cout << "Element " << key << " not found in the list." << endl;
            return head;
        }

        prev->next = temp->next;
        delete temp;
    }

    return head;
}

int main() {

    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
    Node* fourth = nullptr;

    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    cout << "Original Linked List:" << endl;
    linkedListTraversal(head);

    int newData = 5;
    head = insertAtFirst(head, newData);
    cout << "\nLinked List after inserting " << newData << " at the beginning:" << endl;
    linkedListTraversal(head);

    int deleteData = 3;
    head = deleteNode(head, deleteData);
    cout << "\nLinked List after deleting " << deleteData << ":" << endl;
    linkedListTraversal(head);

    return 0;
}