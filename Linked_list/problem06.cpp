
#include<iostream>
#include"linked_list.cpp"

using namespace std;

int my_is_palindrome(node *& start)
{
    if (start == NULL && start->next == NULL)
        return true;
    
    node * slow, * fast , *temp = start;
    slow = fast = start;

    while(fast ->next != NULL && fast->next->next != NULL)
    {
        slow = slow ->next;
        fast = fast->next->next;
    }
    node * mid = slow;
    slow->next = reverse(slow ->next);
    slow = slow ->next;



    while(slow != NULL)
    {
        if(temp ->data != slow ->data)
        {
            slow = mid;
            slow ->next = reverse(slow ->next);
            return false;
        }
        temp = temp ->next;
        slow = slow ->next;      
    }
    slow = mid;
    slow ->next = reverse(slow ->next);
    return true;
    
}


int main()
{
    node * start = NULL;
    insert(start , 1 , 10);
    insert(start , 2 , 20);
    //insert(start , 3 , 4);
    insert(start , 4 , 20);
    insert(start , 5 , 10);

    print_list(start);
    cout << my_is_palindrome(start)<<"\n";
    print_list(start);

    return 0;
}