
//Adding two number
#include<iostream>
#include"linked_list.cpp"

using namespace std;

node *Add1(node *l1 , node * l2)
{
    node * list1 = l1 , * list2 = l2;
    node *dummy = new node();dummy->data = 0;
    node *temp = dummy;int carry = 0;
    while(list1 != NULL || list2 != NULL || carry == 1 )
    {   
        int sum = 0;
        if(list1 != NULL)
        {
            sum += list1->data;
            list1 = list1->next;
        }

        if(list2 != NULL)
        {
            sum += list2->data;
            list2 = list2->next;
        }

        sum += carry;
        carry = sum / 10;
        node * new_node = new node();
        new_node-> data = sum%10; 
        new_node ->next = NULL;
        temp ->next = new_node ;
        temp = temp -> next ;

    } 
    return dummy->next;

}

int main()
{
     node * start = NULL;
    node * start1 = NULL;
   // 3 34 56 4567 55 34 5 56
    insert(start , 1 , 5);
    insert(start , 2 , 6);
    insert(start , 3 , 4);
    insert(start , 4 , 6);
    insert(start , 5 , 3);
    insert(start , 6 , 1);
       
    insert(start1 , 1 , 4);
    insert(start1 , 2 , 7);
    insert(start1 , 3 , 2);
    insert(start1 , 4 , 2);
    insert(start1 , 5 , 3);

    
    print_list(start);
    print_list(start1);

    start1 = Add1(start , start1);
    print_list(start1);
   
}