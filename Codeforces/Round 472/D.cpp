/*input
9
0 1 0 1 1 4 0 4 8
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x)
#define loop(start,end) for(ll var = start; var < end; var++)
#define arr(a,n) loop(0,n) in(a[var])
#define parr(a,n) loop(0,n) printf("%lld ", a[var]);
const ll MOD = 1e9 + 7;



int main(){
	ll n;
	cin>>n;
	ll a[n+1],prefixMax[n+1];
	prefixMax[0] = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		
	}

	

	ll created = 0;

	for(ll i = 0;i<n;i++){
		
		if(a[i]<created){
			ans += created - a[i];
		}
		else{
			ll extra = a[i] - created;
			created = a[i] ;
			ans += extra * (extra - 1)/2;
		}
		
	}

	cout<<ans;

	return 0;
}