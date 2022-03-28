//Merge two linked list

#include<iostream>
#include"linked_list.cpp"

using namespace std;

node* mymerge(node *& list1 , node *& list2)
{
    node * tmp = NULL , * temp = NULL;
    if(list1->data > list2->data)
    {
        temp = list1;
        list1 = list2;
        list2 = temp;
    }

    node * result = list1;
    while (list1 != NULL && list2 != NULL)
    {
        while (list1 != NULL && list1->data <= list2->data )
        {
            tmp = list1;
            list1 = list1->next;
        }
        tmp ->next = list2;

        //swap List1 and List2
        temp = list1;
        list1 = list2;
        list2 = temp;
    }
    
    return result;
}

int main()
{
    node * start1 =     NULL ,* start2 =NULL;
    insert(start1 , 1 , 1);
    insert(start1 , 2 , 2);
    insert(start1 , 3 , 3);
    insert(start1 , 4 , 4);
    insert(start1 , 5 , 5);
    insert(start1 , 6 , 6);
    insert(start1 , 7 , 7);
    insert(start1 , 8 , 8);

    insert(start2 , 1 , 0);
    insert(start2 , 2 , 9);
    insert(start2 , 3 , 10);
    insert(start2 , 4 , 11);

    print_list(start1);
    print_list(start2);

     start1 = mymerge(start1 , start2);

    print_list(start1);
    

    return 0;

}