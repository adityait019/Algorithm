#include<stdio.h>
#include<stdlib.h>
//Edge structure 
struct Edge
{
    int src,dist,weight;
};
struct Graph
{
    int V,E;
    //V-Number of Vertex;
    //E-Number of Edges;
    struct Edge* edge;
};
// struct Graph* createGraph(int V,int E)
// {
//     struct Graph* graph;
//     graph->V=V;
//     graph->E=E;
//     for(int i=0;i<E;i++)
//     graph->edge[E];
//     return graph;
// };

void bellman(struct Graph *graph,int src)
{
    int i,j,u,v,w;
    int tv=graph->V;//total vertex
    int te=graph->E;//total edges
    int d[tv];//distance array
    int p[tv];//predecessor array
    for (int i = 0; i < tv; i++)
    {
        d[i]=INT_MAX;
        p[i]=0;
    }
    //marking src vertex as 0
    d[src]=0;
    //relax edges |tv-1| times
    for (i = 0; i < tv-1; i++)
    {
        for ( j = 0; j < te; j++)
        {
            //edge data
            u=graph->edge[j].src;
            v=graph->edge[j].dist;
            w=graph->edge[j].weight;
            if(d[u]!=INT_MAX && (d[u]+w)<d[v])
            {
                d[v]=d[u]+w;
                p[v]=u;
            }
        }
        
    }
    //detect negative cycle if value changes then negative cycle
    for ( i = 0; i < te; i++)
    {
            u=graph->edge[j].src;
            v=graph->edge[j].dist;
            w=graph->edge[j].weight;
            if(d[u]!=INT_MAX && d[v]>d[u]+w)
            {
                printf("Negative weight cycle detected\n");
                return;
            }
    }
    
    //if No negative cycle found 
    printf("Distance array : ");
    display(d,tv);
    printf("Predecessor arrray : ");
    dsplay(p,tv);
    

}
void display(int arr[],int size)
{
    for (int  i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);   
    }
    printf("\n");
    
}
int main()
{
    return 0;
}