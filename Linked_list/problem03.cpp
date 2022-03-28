

// return the node which is starting point of cycle in linked list

#include<iostream>

using namespace std;

#include"linked_list.cpp"

node * starting_point_of_cycle(node *& start)
{
    node * fast , * slow;
    fast = slow = start;
    while(fast && slow && fast->next)
    {
        slow = slow -> next;
        fast = fast -> next->next;
        if (slow == fast)
            break;
    }
    if (slow == NULL || fast == NULL)
        return NULL;
    
    fast = start;
    while( fast != slow)
    {
        fast = fast ->next;
        slow = slow -> next;
    }
    return fast;
}

int main()
{
   printf("Enter the element for creating linked list\n");
    node *first = (struct node *) malloc(sizeof(struct node));
    node *second =  (struct node *)malloc(sizeof(struct node));
    node *third =   (struct node *)malloc(sizeof(struct node));
    node *fourth = (struct node *) malloc(sizeof(struct node));
    node *fifth =  (struct node *) malloc(sizeof(struct node));
    
    
    cin>>first ->data;
    first ->next =second;

    cin>>second ->data;
    second ->next = third;  

    cin>>third ->data;
    third ->next = fourth; 

    cin>>fourth ->data;
    fourth ->next = fifth; 

    cin>>fifth ->data;
    fifth ->next = fourth; 

    
    print_list(first);
    node * starting_point_node = starting_point_of_cycle(first);
    if(starting_point_node)
    {
        cout<<"starting point node "<<starting_point_node->data<<"\n";
    }
    else {
        cout<<"no loop\n";
    }
    

    return 0;
}

