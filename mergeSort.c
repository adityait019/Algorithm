#include<stdio.h>
void mergeSort(int arr[],int lowerbound,int upperbound);
void merge(int arr[],int lowerbound,int mid,int upperbound);
void printArray(int arr[],int size);
struct intvalue
{
    int value;
    int index;
};

int main()
{   
    int arr[100];
    int size;
    printf("Enter the size ");
    scanf("%d",&size);
    printf("Enter Array element ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n Array elements : ");
    printArray(arr,size);
    printf("\nArray after sorting ");
    mergeSort(arr,0,size-1); 
    printArray(arr,size);
    printf("\n");
    printArray(indexTracker,size);
    return 0;
}
void mergeSort(int arr[],int lowerbound,int upperbound)
{
    if (lowerbound<upperbound)
    {
        int mid=lowerbound+(upperbound-lowerbound)/2;
        mergeSort(arr,lowerbound,mid);
        mergeSort(arr,mid+1,upperbound);
        merge(arr,lowerbound,mid,upperbound);
    }
    
}
void merge(int arr[],int lowerbound,int mid,int upperbound)
{
    int i=lowerbound;
    int j=mid+1;
    int k=lowerbound;
    int temp[100];
    
    int l=0;
    while(i<=mid && j<=upperbound)
    {
        if(arr[i]>=arr[j])
        {
            indexTracker[l++]=i;
            temp[k++]=arr[i++];
        }
        else{
            indexTracker[l++]=j;
            temp[k++]=arr[j++];
        }
    }
    for(;i<=mid;i++)
    {
        indexTracker[l++]=i;
        temp[k++]=arr[i];
    }
    for(;j<=upperbound;j++)
    {
        indexTracker[l++]=j;
        temp[k++]=arr[j];
    }
    //updation
    for(int m=0;m<k;m++)
    {
        arr[m]=temp[m];
    }
}
void printArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}