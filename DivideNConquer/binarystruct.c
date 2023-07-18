#include <stdio.h>
struct binary
{
    int leftmost;
    int rightmost;
};
struct binary binarySearch(int arr[],int left,int right,int key);
int main()
{
    struct binary b;
     
    int arr[]={9,12,23,45,67,70,90};
    int val=binarySearch(arr,0,6,67);
    printf("Key is present at %d index",val);
    return 0;
}
//Binary search implementation
struct binary binarySearch(int arr[],int left,int right,int key)
{
    
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==key)
        {
            int leftmost=mid;
            int rightmost=mid;
            while(arr[leftmost]==key)
            {
                leftmost--;
            }
            while(arr[rightmost]==key)
            {
                rightmost++;
            }
            return mid;
        }
        else if(arr[mid]>key)
        {
            right=mid-1;

        }
        else
        {
            left=mid+1;
        }
    
    }
    return -1;
}
