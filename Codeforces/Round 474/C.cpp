/*input
167959139 481199252
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 7;

int main(){	
	ll x,d;
	in(x);
	in(d);

	ll initial = 1;
	vector<ll> vec;

	for(int i = 50;i>=0;i--){
		if(x&(1LL<<i)){
			for(int j = 0;j<i;j++){
				vec.push_back(initial);

			}

			initial += d;
			vec.push_back(initial);
			initial += d;
		}
	}

	cout<<vec.size()<<"\n";
	for(ll x : vec){
		cout<<x<<" ";
	}

	return 0;
}