/*input
28 3
30 32 36
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k;
    cin>>n>>k;
    ll a[k];
    ll left = LLONG_MAX;
    ll type = -1,box = 0;
    if(n==0){
    	cout<<"1 0";
    	return 0;
    }
    for(int i=0;i<k;i++)
    {
    	cin>>a[i];
    	ll abox = n/a[i];
    	if((n-abox * a[i]) < left )
    	{
    		left = n-abox * a[i];
    		box = abox;
    		type = i+1;
    	}
    }
    cout<<type<<" "<<box;
	return 0;
}