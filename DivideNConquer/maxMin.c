#include<stdio.h>
void maxMin(int arr[],int left,int right)
{
    int max;
    int min;
   if(left==right)
   {
    max=arr[left];
    min=arr[left];
   }
   else if(left+1==right)
   {
        if(arr[left]<arr[right])
        {
            min=arr[left];
            max=arr[right];
        }
        else{
            max=arr[left];
            min=arr[right];
        }
   }
   else
   {
    int mid=left+(right-left)/2;
    maxMin(arr,left,mid);
    maxMin(arr,mid+1,right);
    if(leftpart[0]>rightpart[0])
    {
        max=leftpart[0];
    }
    else{
        max=rightpart[0];
    }
    if(leftpart[1]<rightpart[1])
    {
        min=leftpart[1];
    }
    else{
        min=rightpart[1];
    }
   }
   int ans[2]={max,min};
   return ans;
}
int main()
{
    int size;
    int arr[]={45,6,35,8,9,10,12};
    
    int ans[]=maxMin(arr,0,6);  
    for(int i=0;i<2;i++)
    {
        printf("%d ",ans[i]);
    }
    
        return 0;
}