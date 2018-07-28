/*input
3 1 0
0 0 0
1 0 0
2 0 0
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll n,a,b;
	cin>>n>>a>>b;
	map< pair<ll,ll>,ll > mp;
	for(int i = 0;i<n;i++){
		ll x,vx,vy;
		cin>>x>>vx>>vy;
		mp[{vx,vy}]++;
	}
	
	map<ll,ll> sol;

	for(auto itr : mp){
		pair<ll,ll> p = itr.first;
		ll b = a*p.first - p.second;
		sol[b]++;
	}
	
	ll answer = 0;

	for(auto itr : sol){
		answer += itr.second * (itr.second - 1) / 2;

	}

	cout<<answer;
	return 0;
}