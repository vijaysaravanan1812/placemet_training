

// removing duplicates
#include <iostream>
#include "linked_list.cpp"

using namespace std;

// void remove_duplicates(node *&start)
// {
//     static int count = 1;
//     node *prev = NULL, *temp = start;
//     while (temp != NULL)
//     {

//         while (temp->data != temp->next->data)
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//         cout << "prev " << prev->data << "\n";
//         cout << "temp " << temp->data << "\n";
//         int duplicate = temp->data;
//         while ( temp->data == duplicate)
//         {
//             node *tmp = temp;
//             temp = temp->next;
//             prev->next = temp;
//             free(tmp);
//         }
//         print_list(start);
//     }
// }

void remove_duplicates(node *& start)
{
    node * temp , * prev = NULL;

}


int main()
{
    node *start = NULL;
    insert(start, 1, 1);
    insert(start, 3, 2);
    insert(start, 3, 3);
    insert(start, 4, 3);
    insert(start, 5, 5);
    insert(start, 6, 5);
    insert(start, 7, 6);
    insert(start, 7, 6);
    insert(start, 9, 9);

    print_list(start);
    remove_duplicates(start);
    print_list(start);
}
