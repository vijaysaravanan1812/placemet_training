
// Union of two linnked list
#include<iostream>
#include<set>
#include"linked_list.cpp"

using namespace std;

node * Union(node * head1 , node * head2)
{
    set<int> s1;
    node * temp = head1;

    while (temp != NULL){
        s1.insert(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while(temp != NULL){
        s1.insert(temp ->data);
        temp= temp ->next;
    }
    int l1 = length(head1);
     int l2 = length(head2);
     
    clear(head1);
    clear(head2);
     int i = 0;
     set <int>::iterator itr;  
    
    for(itr = s1.begin() ; itr != s1.end() ; itr++, i++){
        insert(head1 , i++ , *itr);

    }

    return  head1;
}




int main()
{
    node * start1 = NULL;
    node * start2 = NULL;
    insert(start1 ,1, 12);
    insert(start1  ,1, 24);
        insert(start1 ,1, 32);
    insert(start1  ,1, 64);
        insert(start1 ,1, 22);
    insert(start1  ,1, 84);
        insert(start1 ,1, 42);
    insert(start1  ,1, 94);

        insert(start2 ,1, 23);
    insert(start2  ,1, 24);
        insert(start2 ,1, 12);
    insert(start2  ,1, 43);
        insert(start2 ,1, 42);
    insert(start2  ,1, 84);
 print_list(start1);
  print_list(start2);
    start1 = Union(start1 , start2);
   print_list(start1);

    return 0;
}