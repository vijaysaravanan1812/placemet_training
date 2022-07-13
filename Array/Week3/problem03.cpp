

#include<iostream>


using namespace std;


int maxIndexDiff(int arr[] , int n){
    int i = 0 ;
    int j = n -1 ;
    int max_len = 0 ;
    while(i < n){
        int key = arr[i];
        j = n -1;
        while(j >= i){
            if(arr[j ] >= key){
                max_len = max(max_len , j - i );
                break;
            }

            j --;
        }
        i++;
    }
    return max_len;

}