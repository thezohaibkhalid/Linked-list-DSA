#include <iostream>
using namespace std; 
struct Node {
    int data;
    Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != nullptr) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = new Node;
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// Case 2insertAtIndex(struct N
struct Node* insertAtIndex (Node head, int data, int index) {
    Node* temp= new Node;
    temp -> data = data;
    Node* p = new Node;
    p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }    
    temp->next = p->next;
    p->next = temp;
    return head;
}

// Case 3
struct Node* insertAtEnd( Node* head, int data) {
     Node* ptr = new Node;
    ptr->data = data;
     Node* p = head;

    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = nullptr;
    return head;
}

// Case 4
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
     Node* ptr = new Node;
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

int main() {
    struct Node* head = new Node;
    struct Node* second = new Node;
    struct Node* third = new Node;
    struct Node* fourth = new Node;

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = nullptr;

    cout << "Linked list before insertion" << endl;
    linkedListTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 56, 1);
    // head = insertAtEnd(head, 56);
    head = insertAfterNode(head, third, 45);
    cout << "\nLinked list after insertion" << endl;
    linkedListTraversal(head);

    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
