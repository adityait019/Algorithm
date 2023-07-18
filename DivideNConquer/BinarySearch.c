#include<stdio.h>
int binarySearch(int arr[],int left,int right,int key);
int main()
{
    int arr[]={9,12,23,45,67,70,90};
    int val=binarySearch(arr,0,6,67);
    printf("Key is present at %d index",val);
    return 0;
}
//Binary search implementation
int binarySearch(int arr[],int left,int right,int key)
{
    int mid=left+(right-left)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    else if(arr[mid]>key)
    {
        right=mid-1;
        return binarySearch(arr,left,right,key);
    }
    else{
        left=mid+1;
    }
    return binarySearch(arr,left,right,key);
    
    return -1;
}