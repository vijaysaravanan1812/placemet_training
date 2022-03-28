

#include<iostream>
#include"linked_list.cpp"

using namespace std;

// pairwise swap node
node * pairwise_swap(node *& head1)
{
    node * dummy =     (node *)malloc(sizeof(node));
    dummy ->data = 0;
    dummy ->next = head1;
    node *cur = head1 ,* prev = dummy;

    while (cur != NULL && cur ->next != NULL)
    {
        prev->next = cur->next;
        cur->next = cur->next->next;
        prev->next->next = cur;
        cur = cur->next;
        prev = prev->next->next;

    }
    
    return dummy->next;


} 

int main()
{
    node *start = NULL;
    insert(start , 1 , 34);
    insert(start , 2 , 46);
    insert(start , 3 , 68);
    insert(start , 4 , 75);
    insert(start , 5 , 84);

    print_list(start);
   start = pairwise_swap(start);
    print_list(start);
    return 0;
}