#include<stdio.h>
void mergeSort(int a[],int low,int high);
void merge(int a[],int low,int mid,int high); 
int main()
{
    int a[5]={78,53,67,2,1};
    mergeSort(a,0,4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    
    return 0;
}
void merge(int a[],int low,int mid,int high)
{
    int i=0,j=mid+1,k=0;
    int half1=mid-low+1;
    int half2=high-mid;
    int temp[100];
    while(i<half1&&j<half2)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<half1)
    {
        temp[k++]=a[i++];
    }
    while(j<half2)
    {
        temp[k++]=a[j++];
    }
//updating in original array
    for (int i = 0; i < k; i++)
    {
        a[i]=temp[i];
    }
}
void mergeSort(int a[],int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}