/*input
7
URRRUUU
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = (1e9) + 7;
const ll MAX = (1e6) + 1;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll x = 0, y = 0;
    ll curr = 0;
    ll count = 0;
    for(ll  i =0;i<n;i++)
    {
    	if(s[i]=='R')
    	{
    		x=x+1;
    	}
    	else
    	{
    		y=y+1;
    	}
    	if(curr==1 && x>y)
    	{
    		curr = 2;
    		count++;
    	}
    	else if(curr == 2 && x<y)
    	{
    		curr = 1;
    		count++;
    	}

    	if(x>y)
    		curr = 2;
    	else if(x<y)
    		curr = 1;
    }
    cout<<count;
	return 0;
}