
// Given the root of a binary tree, calculate the vertical order traversal 
// of the binary tree.

// For each node at position (row, col), its left and right children will 
// be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. 
// The root of the tree is at (0, 0).u

// The vertical order traversal of a binary tree is a list of top-to-bottom
// orderings for each column index starting from the leftmost column and
// ending on the rightmost column. There may be multiple nodes in the same 
// row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include"tree.cpp"

using namespace std;

void solve(map<int , map <int , set<int>>> &mymap , node * cur , int col, int row){
    if(!cur)
        return;

    mymap[col][row].insert(cur->data);
    cout<<cur->data<<" : "<<col<<"\n";
    solve(mymap , cur->left , col - 1 , row + 1);
    solve(mymap , cur->right , col + 1 , row + 1);
}

vector<vector<int>>  vertical_order_traversal(node * root ){
    map<int , map<int , set <int>>> mymap ;
    solve(mymap , root , 0 , 0);
    vector<vector <int>> ans;

    for(auto m1: mymap){
        vector<int> temp ;
        for(auto m2 : m1.second){
            for(auto m3 : m2.second){
                temp.push_back(m3);
               
            }   
             
            for( auto y : temp){
                cout<<y<<" ";
            }
            cout<<"\n";

                        
        }
        
        ans.push_back(temp);
    }

    return ans;

}


int main()
{
    node *root = NULL;

    insert(root, 84);
    insert(root, 54);
    insert(root, 104);
    insert(root , 34);
    insert(root, 68);
    insert(root, 95);

    insert(root, 120);
    insert(root, 10);
    insert(root, 42);
    insert(root, 59);
    insert(root, 76);
    insert(root, 92);
    insert(root, 99);
    insert(root, 110);
    insert(root, 130);
    insert(root, 15);
    insert(root, 70);

    vector < vector <int>> ans  = vertical_order_traversal(root);

    cout<<"------------------\n";
    for(auto x : ans){
        for( auto y : x){
            cout<<y<<" ";
        }
        cout<<"\n";
    }

    return 0;

}

