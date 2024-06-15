#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *next;
};
 
void linkedListTraversal( Node *ptr)
{
    while (ptr != NULL)
    {
        cout<< ptr->data;
        ptr = ptr->next;
    }
}

int main()
{
    // struct Node *head;
    // struct Node *second;
    // struct Node *third;
    // struct Node *fourth;
 
    // Allocate memory for nodes in the linked list in Heap
    // head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // fourth = (struct Node *)malloc(sizeof(struct Node));

    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth= new Node;
 
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
    fourth->next = NULL;
 
    linkedListTraversal(head);
    return 0;
}