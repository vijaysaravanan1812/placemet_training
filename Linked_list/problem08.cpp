

// rotation of linked list


#include<iostream>
#include"linked_list.cpp"

using namespace std;

void rotation (node *& start , int n)
{
    node * current_node , * previous_node ;
    current_node = previous_node = start;
    for(int i = 1 ; i <= n; i++)
    {
        while( current_node ->next != NULL)
        {
            previous_node =  current_node;
            current_node  = current_node->next;
        }
        previous_node->next = NULL;
        current_node->next = start;
        start = current_node;
    }
}

int main()
{
    node * start = NULL;
    insert(start , 1 , 21);
    insert(start , 3 , 43);
    insert(start , 3 , 29);
    insert(start , 4 , 30);

    print_list(start);
    rotation(start , 3);
    print_list(start);


    return 0;
}