/*input
11
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
    ll count = 0;
    for(int i =1;i<=n/2;i++)
    {
    	if((n-i)%i==0)
    		count++;
    }

    cout<<count;
	return 0;
}