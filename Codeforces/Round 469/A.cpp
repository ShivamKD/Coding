/*input
4 4 3
*/
#include <bits/stdc++.h>
using namespace std;

#define in(x) scanf("%lld",&x)
#define ll long long

const ll MOD = 1e9 + 7;


int main(){


	ll r,l,a;

	cin>>l>>r>>a;
	
	ll ans = 0;

	if(r<l){
		ll req = l - r;
		r = r + min(a,req);

		a -= min(a,req);

		ans = r * 2 + (a/2) * 2;
	}
	else{
		ll req = r - l;
		l = l + min(a,req);

		a -= min(a,req);

		ans = l * 2  + (a/2) * 2;
	}

	cout<<ans;

//	cout<<min(r,l)*2 + 1;
	return 0;
}