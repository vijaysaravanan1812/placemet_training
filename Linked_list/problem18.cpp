// quick sort on linked list

#include <iostream>
#include "linked_list.cpp"

using namespace std;

node * get_tail(node * head)
{
    node * temp = head;
    while (temp->next != NULL)
    {
        temp = temp ->next;
    }
    return temp;
}

node *partition(node *Head, node *End, node **newHead, node **newEnd)
{
    node *prev = NULL, *cur = Head, *pivot = End, *tail = pivot;
    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if (*newHead == NULL)
                *newHead = cur;

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            
            tail = cur;
            cur = tmp;
        }

    }

    if(*newHead == NULL)
        *newHead = pivot;
    (*newEnd) = tail;

    return  pivot;
}

node * quicksort(node *head , node *end)
{
    if(  !head || head == end)
        return head;
    node *newHead = NULL , *newEnd = NULL;

    node *pivot = partition(head , end , &newHead , &newEnd);

    if(newHead != pivot )
    {
        node *tmp = newHead;
        while(tmp ->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        newHead = quicksort(newHead , tmp);

        tmp = get_tail(newHead);
        tmp->next = pivot;
    }

    pivot->next = quicksort(pivot->next , newEnd);

    return newHead;
}


int main()
{
    
    node * start = NULL;

   // 3 34 56 4567 55 34 5 56
    insert(start , 1 , 5);
    insert(start , 2 , 34);
    insert(start , 3 , 4567);
    insert(start , 4 , 55);
    insert(start , 5 , 33);
    insert(start , 5 , 54);
    insert(start , 5 , 56);
    
    print_list(start);
    node * tmp = get_tail(start);
    start = quicksort(start , tmp);
    print_list(start);
    return 0;
}
