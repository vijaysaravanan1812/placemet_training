//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    StackNode * new_node = new StackNode(x);
    if(top == NULL)
    {
        top  = new_node;
    }    
    else {
        new_node ->next  = top;
        top = new_node;
    }
    
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(top != NULL){
    StackNode * tmp = top;
    top  = top -> next;
    int x = tmp ->data;
    delete tmp;
    return x;
    
    } 
    else{
        return -1;
    }
    
}