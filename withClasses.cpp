#include <iostream>
using namespace std;

class node{
    public:
    node* next;
    int data;

    node(int a){
        data = a;
    }

};
// This code was of insert as last or tail
void InsertAtLast( node* &head, int a){
    node* n = new node(a);
    
    if(head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = n;
}


struct node*(Node* head, int data, int index) {
    Node* ptr = new node;
    Node* p = new node;
    p = head;
    int i = 0;

    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


void InsertAtHead(node* &head, int val)
{
    node*n = new node(val);
    n->next = head;
    head = n;
}
void display(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node* head = NULL;
//This code was of insert at last or tail
    InsertAtLast(head, 1);
    InsertAtLast(head, 2);
    display(head);

    InsertAtHead(head, 122);
    display(head);

    return 0;
}