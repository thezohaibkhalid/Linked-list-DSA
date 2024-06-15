// #include <iostream>
// using namespace std;
// int main()
// {
// typedef struct node{
//     int number;
//     node *next;
// }
// node;

// //node *n = malloc(sizeof(1));
// node *n = new node;
// n->number = 1;
// n->next = 10;

// cout << "It is " << n->next;
// }

#include <iostream>
using namespace std;

// Define the node struct
struct node {
    int number;
    node* next;
};

int main() {
    // Create a node object
    node* n1 = new node;  // Allocate memory for the node

    // Initialize the node members using dereferencing (*)
    (*n1).number = 5;      // Set the 'number' member
    (*n1).next = nullptr;  // Set the 'next' pointer to nullptr

    // Print the 'next' pointer value
    cout << "n1->next: " << (*n1).next << endl;
    cout << n1->number;

    // Deallocate memory
    delete n1;

    return 0;
}
