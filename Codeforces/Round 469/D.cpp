/*input
13 4
10
5
4
8
*/
#include <bits/stdc++.h>
using namespace std;

#define in(x) scanf("%lld",&x)
#define ll long long

const ll MOD = 1e9 + 7;


int main(){

	ll n,q;
	cin>>n>>q;

	while(q--){
		ll x;
		cin>>x;
		if(x%2==1){
			cout<<(x/2)+1<<"\n";
		}
		else{

			ll move = n -  x / 2;
			ll current = x + move;

			while(!(move%2)){
				move/=2;
				current+=move;
			}
			ll ans = current/2 + 1;
			cout<<ans<<"\n";

		}
	}

	return 0;
}