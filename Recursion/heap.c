#include<stdio.h>
#include<stdlib.h>
void swap(int x,int y)
{
    int temp=x;
    x=y;
    y=temp;
}
void maxHeapify(int arr[],int size,int i)
{
    int left=2*i;
    int right=(2*i)+1;
    int largest=i;
    if((arr[left]>arr[largest]) && (left<size))
    largest=left;
    if((arr[right]>arr[largest]) && (right<size))
    largest=right;
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);
        maxHeapify(arr,size,largest);
    }
}
void buildHeap(int arr[])
{
    int size=sizeof(arr)/sizeof(arr[0]); 
    for(int i=size/2-1;i>=0;i--)
    {
        maxHeapify(arr,size,i);
    }
    for(int k=0;k<size;k++)   
    {
        printf("%d ",arr[k]);
    }
}

int main()
{
    int size;
    int arr[20];
    scanf("%d",&size);
    printf("\n Enter array element : ");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n After building heap : ");
    buildHeap(arr);
    
    return 0;
}