/*input
1
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll k;

    cin>>k;

    if(k>36)
    	cout<<"-1";
    else
    {
    	ll ans = 0;
    	while(k>1)
    	{
    		ans = ans*10 +8;
    		k=k-2;
    	}
    	if(k==1)
    		ans =  ans * 10 +4;
    	cout<<ans;
    }

	return 0;
}