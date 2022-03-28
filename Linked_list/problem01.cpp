

// reverse linked list

#include<iostream>
using namespace std;

#include"linked_list.cpp"

node * myreverse(node *& start)
{
    node * previous_node = NULL , *next_node , *current_node ;
    current_node = next_node = start;
    while(next_node != NULL)
    {
        next_node = next_node ->next;
        current_node ->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    start = previous_node;
    return previous_node;
}

int main()
{
    node * start = NULL;
    insert(start , 1, 13);
    insert(start , 2 , 15);
    insert(start , 3 , 17);
    insert(start , 4 , 18);

    print_list(start);

    myreverse(start);

    print_list(start);

    return 0 ;


}