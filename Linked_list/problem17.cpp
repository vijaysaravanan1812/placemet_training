
// Swap the given two node in linked list
#include<iostream>
#include"linked_list.cpp"

using namespace std;

void myswap(node *& head , int x , int y)
{
    
    if(x == y) 
        return;

    
    
    node *currY, * prevX = NULL;
    node * currX, *prevY = NULL, *temp = NULL;
    currY = head;
     currX = head;
    
      //find x value in linked list
    while(currX && currX -> data != x)
    {
        
        prevX  = currX;
        currX = currX->next;
      
    }


    //find Y value
    while(currY != NULL && currY->data != y)
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

    //changing next pointer
    temp = currX->next;
    currX -> next = currY ->next;
    currY->next = temp;
    

}

int main()
{
    node * start = NULL;
    insert(start , 1 , 34);
    insert(start , 2 , 24);
    insert(start , 3 , 45);
    insert(start , 4 , 35);
    insert(start , 5 , 53);

    print_list(start);
    myswap(start , 35 , 34);
    print_list(start);

    return 0;

}