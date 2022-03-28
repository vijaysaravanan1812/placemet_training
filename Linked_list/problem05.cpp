// find the intersection of two linked list

#include<iostream>
#include"linked_list.cpp"

using namespace std;

// find intersection 
node * my_find_intersection(node *& start, node *& start2)
{
    if(start == NULL || start2 == NULL)
        return NULL;

    node * a = start;
    node * b = start2;

    while(a != b)
    {
        if(a == NULL)
        {
            a = start2;
        }
        else{
            a = a->next;
        }
        if(b == NULL)
        {
            b = start;
        }
        else{
            b = b ->next;
        }
    }
  
    return a;

}

int main()
{
    node * start = NULL;
    node * start2 = NULL;
    node * start3 = NULL;

    insert(start , 1, 4);
    insert(start , 2 , 5);
    insert(start , 4 , 9);
    insert(start , 5, 7);
    
    
    insert(start2 , 1, 14);
    insert(start2 , 2 , 15);
    insert(start2 , 3 , 19);
    insert(start2 , 4, 17);

    insert(start3 , 1, 24);
    insert(start3 , 2 , 25);
    insert(start3 , 3 , 29);
    insert(start3 , 4, 27);

    start->next->next->next->next = start3->next->next;
    start2->next->next->next->next = start3->next;


    print_list(start);
    print_list(start2);

    node * common = my_find_intersection(start , start2);
    if (common != NULL)
    {
        cout<<"common node "<<common->data<<"\n";
    }
    else 
    {
        cout<<"No common node\n";
    }
    

    return 0;
}