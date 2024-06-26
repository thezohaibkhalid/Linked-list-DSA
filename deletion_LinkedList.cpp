#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr) {
    while (ptr != nullptr) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1: Deleting the first element from the linked list
struct Node* deleteFirst(struct Node* head) {
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node* deleteAtIndex(struct Node* head, int index) {
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index - 1; i++) {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
}

// Case 3: Deleting the last element
struct Node* deleteAtLast(struct Node* head) {
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != nullptr) {
        p = p->next;
        q = q->next;
    }

    p->next = nullptr;
    free(q);
    return head;
}

// Case 4: Deleting the element with a given value from the linked list
struct Node* deleteByValue(struct Node* head, int value) {
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->data != value && q->next != nullptr) {
        p = p->next;
        q = q->next;
    }

    if (q->data == value) {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main() {
    struct Node* head = new Node;
    struct Node* second = new Node;
    struct Node* third = new Node;
    struct Node* fourth = new Node;

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = nullptr;

    cout << "Linked list before deletion" << endl;
    linkedListTraversal(head);

    // head = deleteFirst(head); // For deleting the first element of the linked list
    // head = deleteAtIndex(head, 2);
    head = deleteAtLast(head);
    cout << "Linked list after deletion" << endl;
    linkedListTraversal(head);

    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}
