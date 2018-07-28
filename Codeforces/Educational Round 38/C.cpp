/*input
3
35
96
1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
    	ll x;
    	cin>>x;
    	if(x==0)
    	{
    		cout<<"1 1\n";
    		continue;
    	}	

    	int flag =0;
    	ll n = (ll)(sqrt(x) + 1);
    	while((n*n - (n/2) * (n/2)) <= x)
    	{
    	    	ll gap = n*n - x;
    			if(gap<0)
    			{
    				n++;
    				continue;
    			}
    			
    			
    	    	ll m = (ll)(sqrt(gap));
    	
    	    	if(m*m==gap)
    	    	{
    	    		ll f = n / m;
    	    		if(n/(f+1)==m)
    	    			f++;
    	    		else if(n/f == m)
    	    			;
    	    		else
    	    		{
    	    			n++;
    	    			continue;
    	    		}
    	    		
    	    		cout<<n<<" "<<f<<"\n";
    	    		flag = 1;
    	    		break;
    	    	}
    	    	n++;
    	}
    	if(!flag)
    		cout<<"-1\n";
    }

	return 0;
}