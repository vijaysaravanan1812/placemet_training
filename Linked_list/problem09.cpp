
// get nth node from last

#include<iostream>
#include"linked_list.cpp"

using namespace std;

node *temp =    (node *)malloc(sizeof(node));

node* get_nth_node_from_last(node* head,int n)
{
    
    if (head == NULL)
        return NULL;
    static int i = 0;
    get_nth_node_from_last(head->next,n);
    if (++i == n)
    {
        temp = head;
      
    }

      return temp;
    
    
    
    
}



int main()
{
    node * start = NULL;
    insert(start , 29,1);insert(start ,34,2);
    insert(start ,24,3);insert(start ,26,4);   
    insert(start ,28,1);insert(start ,39,2);
    insert(start ,14,3);insert(start ,20,4);
    print_list(start);
    cout<<"3rd node from last "<<get_nth_node_from_last(start,3)->data<<"\n";

    return 0;
}