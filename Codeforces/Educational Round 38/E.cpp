/*input

*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    ll a[n];
    ll fact[n+1];
    fact[0] = 1;
    for(int i =1;i<=n;i++)
    {
    	fact[i] = fact[i-1] * i;
    	fact[i]%=MOD:
    }
    for(int i =0 ;i<n;i++)
    	cin>>a[i];

    sort(a,a+n);

    
	return 0;
}