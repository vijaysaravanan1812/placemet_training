
//  Doubly linked list
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};
void print_list_last(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
        cout << "\n";
    }
}

void print_list(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
        cout << "\n";
    }
}

node *get_node(node *&temp, int data)
{
    temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}

node *insert(node *&head, node *&tail, int pos, int data)
{
    node *new_node;
    int i = 1;
    get_node(new_node, data);
    if (head == NULL)
    {
        tail = head = new_node;
    }
    else if (head != NULL)
    {
        node *temp = head;
        while (temp->right != NULL && i < pos - 1)
        {
            temp = temp->right;
            i++;
        }
        if (pos == 1)
        {
            new_node->right = head;
            new_node->left = NULL;
            head->left = new_node;
            head = new_node;
        }
        else if (temp->right == NULL)
        {
            temp->right = new_node;
            new_node->left = temp;
            new_node->right = NULL;
            temp = new_node;
            tail = temp;
        }
        else
        {
            new_node->right = temp->right;
            new_node->left = temp;
            (temp->right)->left = new_node;
            temp->right = new_node;
        }
    }
}

void delete_node(node *&head, node *&tail, int data)
{
    if (head == NULL)
        return;
    else
    {
        node *temp = head;
        if (head->right == NULL)
        {
            temp = head;
            tail = head = NULL;
            free(temp);
        }
        else if (head->data == data)
        {
            head = head->right;
            head->left = NULL;
            free(temp);
        }
        else
        {
            while (temp != NULL && temp->data != data)
                temp = temp->right;
            if (temp == NULL)
                return;
            else
            {
                if (temp->right == NULL)
                {

                    (temp->left)->right = NULL;
                    tail = temp->left;
                    free(temp);
                    return;
                }
                (temp->left)->right = temp->right;
                (temp->right)->left = temp->left;
                free(temp);
            }
        }
    }
}

void reverse(node *&head, node *&tail)
{

    node *current_node = head, *next_node;
    while (current_node != NULL)
    {
        next_node = current_node->right;
        current_node->right = current_node->left;
        current_node->left = next_node;
        current_node = next_node;
    }

    node *temp = tail;
    tail = head;
    head = temp;
    
}

int main()
{
    node *start = NULL;
    node *tail = NULL;
    insert(start, tail, 111, 42);
    insert(start, tail, 111, 52);
    insert(start, tail, 111, 12);
    insert(start, tail, 2, 72);


    //   delete_node(start , 52);
    print_list_last(tail);
    reverse(start, tail);
    print_list_last(tail);
    delete_node(start, tail, 42);
    delete_node(start, tail, 72);
    print_list(start);
}
