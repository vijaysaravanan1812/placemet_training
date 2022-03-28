
// Merge k linked list
#include <iostream>
#include "linked_list.cpp"

using namespace std;


node* newNode(int data)
{
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    // Number of linked lists
    int k = 3;

    // Number of elements in each list
    int n = 4;

    // an array of pointers storing the
    // head nodes of the linked lists
    node *arr[k];

    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    for (int i = 1; i < k; i++)
    {
        arr[0]  = merge(arr[0], arr[i]);
    }


    print_list(arr[0]);

    return 0;
    
}