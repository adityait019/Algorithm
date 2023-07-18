
#include<stdio.h>
struct ratio
{
    float val;
    int index;
};
void mergeSort(struct ratio oi[],int lowerbound,int upperbound);
void printArray(struct ratio oi[] , int size);
void merge(struct ratio oi[],int lowerbound,int mid,int upperbound);
void knapsack(int objectSize,int bagCapacity,int profit[],int weight[]);

int main()
{
    int objectSize,bagCapacity, profit[20], weight[20];
    struct ratio o1[20];
    printf("Enter the value for object size :  ");
    scanf("%d",&objectSize);
    printf("\nEnter the value for bagcapacity(knapSack) : ");
    scanf("%d",&bagCapacity);
    printf("\n Enter the values of profit : ");
    for(int i=0;i<objectSize;i++){
        scanf("%d",&profit[i]);
    }
    printf("\n Enter the values of weight : ");
    for(int i=0;i<objectSize;i++){
        scanf("%d",&weight[i]);
    }   
    knapsack(objectSize,bagCapacity,profit,weight);
    printf("\n");

    
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
    printf("\nprinting value ");
    for(int i=0;i<size;i++)
    {
        printf("%.2f ",oi[i].val);
    }
    printf("\n Printing index ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",oi[i].index);
    }
}

//KnapSack Function
void knapsack(int objectSize,int bagCapacity,int profit[],int weight[])
{
    struct ratio x[20];
    float totalProfit=0.0;
    //calculating ratio Pi/Wi and storing it in x[i];
    for(int i=0;i<objectSize;i++)
    {
        x[i].val=(float)profit[i]/weight[i];
        x[i].index=i;

    }
    //sorting the ratio with help of merge Sort  in descending order
    mergeSort(x,0,objectSize-1);
    
    //Logic Part 
    int i=0;
    while (objectSize-1>i)
    {
        if(bagCapacity>weight[x[i].index])
        {
            
            bagCapacity -=weight[x[i].index];
            totalProfit +=(profit[x[i].index]*1);

            printf("\nthe fraction Value  is 1.0");
    
        }
        else
        break;
        i++;
    }
    float temp1=(float)bagCapacity;
    float temp2=(float)weight[x[i].index]; 
    double value=(float) (temp1/temp2);
    printf("the frcation value is %.2f ",value);
    totalProfit +=(float)(profit[x[i].index]*value);
     printf("\nTotal profit %.2f " ,totalProfit);
     printArray(x,objectSize);
}
