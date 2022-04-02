

// insert the element in circular  sorted linked list 
 
#include<iostream>
#include "Linked_list.cpp"

using namespace std;
node * get_tail1(node * head)
{
    node * temp = head;
    while (temp->next != head)
    {
        temp = temp ->next;
    }
    return temp;
}

void print_list1(node *&start)
{
    if (start == NULL)
        cout << "No list found\n";
    else
    {
        node *temp = start;
        while (temp->next != start)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<temp->data<<" \n";
    }
}


node *sortedInsert(node *head, int data)
{
    node *new_node,* current = head;
    get_node(data , new_node);
    if(current == NULL)
    {
        new_node ->next = new_node;
        head = new_node;
    }
    else if(data <= head->data){
        node *tmp = head;
        while(tmp->next != head)
            tmp = tmp ->next;
        new_node->next = head;
        tmp ->next = new_node;
        head = new_node;
    }
    else {
        node * tmp = current;
        while( tmp ->next != head && tmp->next ->data < data )
            tmp = tmp ->next;
        new_node->next = tmp->next;
        tmp->next = new_node;
    }

    return head;
}

int main()
{
       node *first = NULL;
    node *second = NULL;
    node *third = NULL;
    node *fourth = NULL;
    node *fifth = NULL;

    first = new node();
    second = new node();
    third = new node();
    fourth = new node();
    fifth = new node();

    first ->data = 2;
    first ->next = second;

    second ->data = 4;
    second ->next = third;

    third ->data = 6;
    third ->next = fourth;

    fourth ->data = 8;
    fourth ->next = fifth;

    fifth ->data  = 10;
    fifth ->next = first;

    print_list1(first);
    first = sortedInsert(first , 7);
    print_list1(first);

}