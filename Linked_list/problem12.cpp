// You are given a pointer/ reference to the node which is to be deleted
// from the linked list of N nodes. The task is to delete the node.
// Pointer/ reference to head node is not given. 
// Note: No head reference is given to you. It is guaranteed that
// the node to be deleted is not a tail node in the linked list.

#include<iostream>
#include"linked_list.cpp"

using namespace std;

void remove_node(node *& del)
{
    node *temp;
    if (del ->next->next == NULL)
    {
        temp = del->next;
        del->data = del->next->data;
        del->next = NULL;
        free(temp);
    }
    else{
        temp = del->next;
        del->data = del->next->data;
        del->next = del->next->next;
        free(temp);

    }
    
}


int main()
{
        node *first = (struct node *) malloc(sizeof(struct node));
    node *second =  (struct node *)malloc(sizeof(struct node));
    node *third =   (struct node *)malloc(sizeof(struct node));
    node *fourth = (struct node *) malloc(sizeof(struct node));
    node *fifth =  (struct node *) malloc(sizeof(struct node));
    
    first ->data = 2;
    first ->next =second;

    second ->data = 4;
    second ->next = third;  

    third ->data = 6;
    third ->next = fourth; 

    fourth ->data = 8;
    fourth ->next = fifth; 

    fifth ->data = 10;
    fifth ->next = NULL; 

    print_list(first);
    remove_node(\ythird);
    print_list(first);

    return 0;
}


