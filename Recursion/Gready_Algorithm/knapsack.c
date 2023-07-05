
/*there aere N objects and knapSack(bag).object i has weight Wi and knapsack
has capacity m i
*/
#include<stdio.h>
struct ratio
{
    float val;
    int index;
};
void mergeSort(struct ratio oi[],int lowerbound,int upperbound);
void printArray(struct ratio oi[] , int size);
void merge(struct ratio oi[],int lowerbound,int mid,int upperbound);

int main()
{
    struct ratio o1[20];
    printf("Enter the value for sorting ");
    for(int i=0;i<6;i++){
        scanf("%d",&o1[i].val);
        o1[i].index=i;
    }
    mergeSort(o1,0,5);
    printArray(o1,6);
    return 0;
}
void mergeSort(struct ratio oi[],int lowerbound,int upperbound)
{
    if (lowerbound<upperbound)
    {
        int mid=lowerbound+(upperbound-lowerbound)/2;
        mergeSort(oi,lowerbound,mid);
        mergeSort(oi,mid+1,upperbound);
        merge(oi,lowerbound,mid,upperbound);
    }
    
}
void merge(struct ratio oi[],int lowerbound,int mid,int upperbound)
{
    int i=lowerbound;
    int j=mid+1;
    int k=lowerbound;
    struct ratio temp[100];
    
    int l=0;
    while(i<=mid && j<=upperbound)
    {
        if(oi[i].val
        >=oi[j].val)
        {
            
            temp[k++]=oi[i++];
        }
        else{
            temp[k++]=oi[j++];
        }
    }
    for(;i<=mid;i++)
    {
        temp[k++]=oi[i];
    }
    for(;j<=upperbound;j++)
    {
        temp[k++]=oi[j];
    }
    //updation
    for(int m=0;m<k;m++)
    {
        oi[m]=temp[m];
    }
}
void printArray(struct ratio oi[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",oi[i].val);
    }
    printf("\n Printing index ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",oi[i].index);
    }
}

//KnapSack Function
int knapsack(int objectSize,int bagCapacity,int profit[],int weight[])
{
   struct ratio x[20];
   float totalProfit=0.0;
    //calculating ratio Pi/Wi and storing it in x[i];
    for(int i=0;i<objectSize;i++)
    {
        x[i].val=profit[i]/weight[i];
        x[i].index=i;

    }
    //sorting the ratio with help of merge Sort  in descending order
    mergeSort(x,0,bagCapacity-1);
    
    //Logic Part 
    int i=0;
    while (objectSize-1>i)
    {
        if(bagCapacity>weight[x[i].index])
        {
            totalProfit +=(profit[x[i].index]*1);
            bagCapacity -=weight[x[i].index];
            printf("\nTotal profit %f " ,totalProfit);
            

        }
    }
    
}
