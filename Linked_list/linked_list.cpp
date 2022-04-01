

// Creating singly linked list

#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};


//count the loop length
int count_loop_length(node *n)
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

// testing loop in linked list
int isloop(node *& start)
{
    node *slow , *fast;
    slow = fast = start;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return 1;
    }
    return 0;
}


// print linked list
void print_list(node *&start)
{
    if (start == NULL)
        cout << "No list found\n";
    else if (isloop(start))
        cout<<"list contain loop\n";
    else
    {
        node *temp = start;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

// print length of list
int length(node *&start)
{
    int i = 1;
    node *temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
        ++i;
    }
    return i-1;
}

// Memory allocation of node
void get_node(int data, node *&temp)
{
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
}

// insert element
void insert(node *&start, int pos, int data)
{
    node *new_node;
    int i = 1;
    get_node(data, new_node);

    if (start == NULL)
    {
        start = new_node;
    }
    else if (pos == 1)
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        node *temp = start;
        while (temp->next != NULL && i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        if (temp->next == NULL)
        {
            temp->next = new_node;
        }
        else
        {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

// delete all node
void clear(node *&start)
{
    node *temp, *prev;
    prev = temp = start;
    while (temp != NULL)
    {
        temp = temp->next;
        free(prev);
        prev = temp;
    }
    start = NULL;
}

// delete the given node
void delete_node(node *&start, int data)
{
    if (start == NULL)
    {
        cout << "No List found\n";
        return;
    }
    node *temp = start;
    node *prev = NULL;
    if (start->data == data)
    {
        start = start->next;
        free(temp);
        return;
    }
    else
    {
        prev = start;
        while(temp != NULL && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "No element found\n";
            return;
        }
        prev->next = temp->next;
        delete temp;   
    }
}


//function to reverse the linked list
node *reverse(node *& start)
{
    node * previous_node = NULL , *next_node , *current_node ;
    current_node = next_node = start;
    while(next_node != NULL)
    {
        next_node = next_node ->next;
        current_node ->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    start = previous_node;
    return previous_node;
}


//check whether given linked list is palindrome
int is_palindrome(node *& start)
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

//merge linked list
node* merge(node *& list1 , node *& list2)
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

void swap(node *& head , node * x , node * y)
{
    
    if(x == y) 
        return;

    node *currY, * prevX = NULL;
    node * currX, *prevY = NULL;
    currY = head;
    currX = head;
    
      //find x value in linked list
    while(currX && currX -> data != x->data)
    {
        prevX  = currX;
        currX = currX->next;    
    }


    //find Y value
    while(currY != NULL && currY->data != y->data)
    {
        prevY = currY ;
        currY = currY ->next;
    }
  

    if(currX == NULL || currY == NULL)
        return;
     
    if(prevX == NULL)
        head = currY;
    else
        prevX ->next = currY;
    
    if(prevY == NULL)
        head = currX;
    else
        prevY ->next = currX;

    node *temp = NULL;
    //changing next pointer
    temp = currX->next;
    currX -> next = currY ->next;
    currY->next = temp;
    

}
// Add operation
node *Add(node *l1 , node * l2)
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
