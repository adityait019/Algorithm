#include<stdio.h>
void quickSort(int arr[],int start,int end);
int partition(int arr[],int start,int end,int pivot);
void swap(int* x,int* y);
int main()
{
    int arr[]={45,6,35,8,9,10,12};
    for (int i = 0; i < 7; i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n after sorting :");
    quickSort(arr,0,6);
    for (int i = 0; i < 7; i++)
    {
        printf(" %d",arr[i]);
    }
    return 0;
}
void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int arr[],int start,int end,int pivot)
{
    while (start<=end)
    {
        while (arr[start]<pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<=end)
        {
            swap(&arr[start],&arr[end]);
            start++;
            end--;
        }
    }
        return start;

    
}
void quickSort(int arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int pivot=arr[(start+end)/2];
    int index=partition(arr,start,end,pivot);
    quickSort(arr,start,index-1);
    quickSort(arr,index,end);
    
}
