#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void reverseString(string s)
{
    int i=0;
    char ans[20];
    int size=s.size();
    while(size>=0)
    {
        ans[i++]=s[size--];
    }
    int temp=0;
    for(int j=0;j<=i;j++)
    {
        s[j]=ans[j];
    }
}
int main()
{
    string s;
    cin>>s;
    reverseString(s);
    cout<<"After reversing string "<<endl;
    cout<<s<<endl;
    return 0;
}