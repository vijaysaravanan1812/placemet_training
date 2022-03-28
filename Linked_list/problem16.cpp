// Given the head of a singly linked list,
// group all the nodes with odd indices
// together followed by the nodes with 
// even indices, and return the reordered list.

#include<iostream>
#include"linked_list.cpp"

using namespace std;

node * odd_even(node *& head)
{
     if(head == NULL && head ->next == NULL && head ->next->next == NULL)
        return head;
    node * even_head = head->next;
    node * odd_head = head;
    node * even  = head->next;
    node * odd = head;

   
    //     print_list(odd);
    // print_list(even);
    while (even && even->next)
    {
         odd->next = odd->next->next;
        even->next = even->next->next;
   
         odd = odd->next;
        even = even->next;
      
    }

    odd->next = even_head;

    return head;

}

int main()
{
    node * start = NULL;
    insert(start , 1 , 34);
    insert(start , 2 , 24);
    insert(start , 3 , 45);
    insert(start , 4 , 35);
    insert(start , 5 , 53);

    print_list(start);
    odd_even(start);
    print_list(start);

    return 0;
}
