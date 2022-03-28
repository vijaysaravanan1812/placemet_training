
//removing duplicates
#include<iostream>

#include"linked_list.cpp"

using namespace std;

node * removing_duplicates(node *& start)
{
    if(start == NULL)
        return NULL;
    node *current_node , *next_node , *previous_node;
    current_node = next_node = start;
    while(current_node ->next != NULL)
    {
        if(current_node ->data == current_node ->next ->data ){
            next_node = current_node ->next ->next;
            free(current_node ->next);
            current_node ->next = next_node;       
        }
        else{
            current_node = current_node->next;
        }
    }
    return NULL;
}


int main()
{
    node * start = NULL;
    insert(start , 1, 10);
    insert(start , 2 , 25);
    insert(start , 3 , 45);
    insert(start , 4 , 45);
    insert(start , 5 , 49);
    insert(start , 6 , 36);
    insert (start , 7 , 36);

    print_list(start);
    removing_duplicates(start);
    print_list(start);


}
