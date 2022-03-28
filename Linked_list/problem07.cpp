
// find the middle of linked list

#include<iostream>
#include"linked_list.cpp"

using namespace std;

node * my_find_middle(node *& start)
{
    node * slow , * fast;
    slow = fast = start;

    while(fast ->next != NULL && fast->next->next != NULL)
    {
        slow = slow ->next;
        fast = fast -> next -> next;
    }

    return slow;

}


int main()
{
    node * start = NULL;
    insert(start , 1 , 10);
    insert(start , 2 , 30);
    insert (start , 3 , 45);
    insert(start , 4 , 49);
    insert (start , 5 , 32);

    print_list(start);
    cout <<" Middle element is "<< my_find_middle(start)->data<<"\n";

    return 0;

}