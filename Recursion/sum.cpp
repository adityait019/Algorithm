#include<iostream>
using namespace std;
int naturalSum(int n)
{
    if(n==0)
    {
        return 0;
    }
    return n+naturalSum(n-1);
}
int main()
{
    int n;
    cin>>n;
    int value=naturalSum(n);
    cout<<value<<endl;
}