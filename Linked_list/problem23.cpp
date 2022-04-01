
//You are given two non-empty linked lists representing 
// two non-negative integers. The most significant digit comes 
// first and each of their nodes contains a single digit. Add 
// the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero,
// except the number 0 itself.

#include<iostream>
#include"linked_list.cpp"

using namespace std;

node * Add2(node *& head1 , node *& head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);
    node * head3 = Add(head1 , head2);
    reverse(head1);
    reverse(head2);
    reverse(head3);

    return head3;
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
    cout<<"  ";
    print_list(start1);
    start1 = Add2(start , start1);

    print_list(start1);
   
}