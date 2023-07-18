#include<stdio.h>
#include<stdlib.h>
struct job
{
    char jobId;
    int profit;
    int deadline;
    int index;
};
void quicksort(struct job j[],int left,int right);
int partition(struct job j[],int left,int mid,int right);
void jobsequence(struct job[],int numberOfjobs);
void swap(struct job *A, struct job *B);
int maxOfdeadlines(struct job j[],int numberOfjob);
int main()
{
    struct job j[5];
    printf("Enter the value of jobid,profit,deadlines : \n");
    for (int i = 0; i < 5; i++)
    {
        
        printf("\n Enter the jodid ,profit,deadlines :");
        scanf("%c%d%d",&j[i].jobId,&j[i].profit,&j[i].deadline);
        j[i].index=i;   
    }
    quicksort(j,0,4);
    printf("\njobId\tprofit\tdeadline index \n");
    for (int i = 0; i < 5; i++)
    {
        printf("%c\t %d\t%d\t%d\n",j[i].profit,j[i].deadline,j[i].index); 
    }
    return 0;
}
void swap(struct job *A, struct job *B){
    struct job temp =*A;
    *A = *B;
    *B = temp;
}

int partition(struct job j[],int left,int mid,int right)
{
    while(left<=right)
    {
        while (j[left].profit>=j[mid].profit)
        {
            left++;
        }
        while (j[right].profit<j[mid].profit)
        {
            right--;
        }
        if(left<=right)
        {
            swap(&(j[left]),&(j[right]));
            left++;
            right--;
        }
        
    }
    return left;
}
void quicksort(struct job j[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    else{
        int pivot=left+(right-left)/2;
        int index=partition(j,left,pivot,right);
        quicksort(j,left,index-1);
        quicksort(j,index,right);

    }
}
int maxOfdeadlines(struct job j[],int numberOfjob)
{
    int max=0;
    for (int i = 0; i <numberOfjob; i++)
    {
        if(j[i].deadline>max)
        {
            max=j[i].deadline;
        }
    }
    return max;
}
void jobsequence(struct job j[],int numberOfjobs)
{
    int totalprofit=0;
    int slot[10]={0};
    quicksort(j,0,numberOfjobs-1);
    int max=maxOfdeadlines(j,numberOfjobs);
    while(max!=0)
    {

    }
}

