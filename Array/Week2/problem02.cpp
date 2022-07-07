/*
 * 2) There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Solution
 * Take minimum size of two array. Possible number of partitions are from 0 to m in m size array.
 * Try every cut in binary search way. When you cut first array at i then you cut second array at (m + n + 1)/2 - i
 * Now try to find the i where a[i-1] <= b[j] and b[j-1] <= a[i]. So this i is partition around which lies the median.
 *
 * Time complexity is O(log(min(x,y))
 * Space complexity is O(1)
*/

#include<iostream>
#include<math.h>

using namespace std;


double merge(int temp1[],int temp2[],int s1,int s2)
{
    //let s1 and s2 be a size of new array
    int arr[s1 + s2];
    int i = 0;
    int j = 0;
    int k = 0;

    //merge the two arrays
    while (i < s1 && j < s2)
    {
        if (temp1[i] <= temp2[j])
        {
            arr[k] = temp1[i];
            i++;
        }
        else
        {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }

    //if any element is temp arrays then copied to original array
    while (i < s1 )
    {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while (j < s2 )
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }
    int size = s1 + s2;
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    if ((size)%2 == 0)
    {
        return (double) (arr[size/2] + arr[size/2 - 1])/2;
    }
    else{
        return (double)arr[size/2];
    }
    
}


double get_median(int arr1[],int arr2[],int size1,int size2)
{
    if(size1 > size2)
    {
        return get_median(arr2,arr1,size2,size1);
    }
    int x = size1,y = size2;

    int low = 0;int high = x;
    while(low <= high)
    {
        int partitionx = low + (high - low)/2;
        int partitiony = (x + y)/2 - partitionx;

        int max_left_x = (partitionx == 0)? -1241012121: arr1[partitionx - 1];
        int min_right_x = (partitionx == x)? 1012012121: arr1[partitionx];
        

        int max_left_y = (partitiony == 0)? -1025101010: arr2[partitiony - 1];
        int min_right_y = (partitiony == y)? 1020101010: arr2[partitiony];

        if (max_left_x <= min_right_y && max_left_y <= min_right_x )
        {
            if ((x + y)%2 == 0)
            {
                printf("max x %d min x %d\nmax y %d min y %d\n",max_left_x,min_right_x,max_left_y,min_right_y);
               return ((double)max(max_left_x,max_left_y) + min(min_right_x,min_right_y))/2;
            }
            else
            {
                printf("max x %d min x %d\nmax y %d min y %d\n",max_left_x,min_right_x,max_left_y,min_right_y);
                return (double)min(min_right_x , min_right_y);
            }
        }
        else if (max_left_x > min_right_y)
        {
            high = partitionx - 1;
        }
        else
        {
            low = partitionx + 1;
        }
    }
    

}

int main()
{
    system("clear");
    printf("Given array \n");
    int arr1[] = {1, 3, 8, 9, 15 };
    int arr2[] = {7, 11, 18 , 19, 21, 25};


    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    for (int i = 0; i < size1; i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for (int j = 0; j < size2; j++)
    {
        printf("%d ",arr2[j]);
    }
    printf("\n");
    printf("----------------------------\n");
    printf("O(log n)\nmedian %lf\n",get_median(arr1,arr2,size1,size2));
    
    printf("----------------------------\n");
    printf("O(n)\nmedian %lf\n",merge(arr1,arr2,size1,size2));
    return 0;
}