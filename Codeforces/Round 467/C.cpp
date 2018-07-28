/*input
3 2 6
*/
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
const ll MOD = (1e9) + 7;
const ll MAX = (1e6) + 1;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,d,t;
    cin>>k>>d>>t;
    if(k%d==0)
    	cout<<t;
    else
    {
    	if(k>=t)
    	{
    		cout<<t;
    		return 0;
    	}

    	double ans = k* 1.0;
    	double left = (d - k%d) / 2.0;
    	ll time = (k+(ll)(left*2));

    	ans += left;

    	ll value = (ll)(t/time);

    	//left = left * time;




    }
	return 0;
}