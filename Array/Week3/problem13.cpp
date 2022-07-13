
//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    if(top1 < top2 - 1)
    {
        arr[++top1] = x;
    }
    else{
        cout<<"overflow\n";
    }
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top1 < top2 - 1)
    {
        arr[--top2] = x;
    }
    else{
        cout<<"Overflow\n";
    }
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1 < 0){
        return -1;
    }
    else{
        int x = arr[top1];
        top1--;
        return x;
    }
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2 > size - 1)
    {
        return -1;
    }
    else{
        int x = arr[top2];
        top2++;
        return x;
    }
}