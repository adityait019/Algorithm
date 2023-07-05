#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int g;
	    cin>>g;
	    while(g--)
	    {
	        int i,n,q;
	        
	        //i=1(head) i=2(tail)
	        
	        // I denotes the initial state of the coins
	        //N denotes the number of coins and rounds
	        //Elephant needs to guess the total number of coins //showing Head or tail 
	        
	        cin>>i>>n>>q;
	        int coin[n];
	        fill_n(coin,n,i);
	        
	        for (int i = 0; i < n; i++)
	        {
	            for(int j=0;j<=i;j++)
	            {
	                if(coin[j]==1)
	                {
	                    coin[j]=2;
	                }
	                else
	                {
	                    coin[j]=1;
	                }
	            }
	        }
	        int cnt=0;
	    for (int i = 0; i < n; i++) 
	    {
	        if(coin[i]==q)
	        {
	            cnt++;
	        }
	   }
	   cout<<cnt<<endl;
	    }
	}
	return 0;
}
