

// count the length of loop in linked_list

#include<iostream>
#include"linked_list.cpp"

using namespace std;

int mycount_loop_length(node *n)
{
    node *temp = n;
    int i =1;
    while (temp -> next != n)
    {
        i++;
        temp = temp ->next;
    }
    return i;

    
}
int detect(node *& start)
{
    node *slow , *fast;
    slow = fast = start;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return mycount_loop_length(slow);
    }
    return 0;
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
    fifth ->next = second; 

    
    print_list(first);
    cout<<"loop length is "<<detect(first)<<"\n";
   
    

    return 0;
}
