#include<stdio.h>
void mergesort(int arr[],int left,int right);
void merge(int arr[],int left,int mid,int right);
int main()
{
     int a[22]={35 ,98, 29, 43, 68, 49, 76, 56, 89 ,99, 50, 85, 66, 59, 18, 80, 19, 21, 62, 88, 42, 24};
    printf("before sorting :");
     for (int i = 0; i < 22; i++)
     { 
        printf("%d ",a[i]);
     }
     mergesort(a,0,21);
     printf("\nAfter sorting :");
     for (int i = 0; i < 22; i++)
     { 
        printf("%d ",a[i]);
     }
     
    return 0;
}
void merge(int arr[],int left,int mid,int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    int temp[right-left+1];
    while (i<=mid && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];  
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right)
    {
        temp[k++]=arr[j++];
    }
    for(int m = left; m <= right; m++)
    {
        arr[m] = temp[m];
    }
}
void mergesort(int arr[],int left,int right)
{
    if(left<right)
    {
    int mid=left+(right-left)/2;
        printf("\nleft : %d and mid: %d and right: %d ",left,mid,right);
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    

}