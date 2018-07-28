/*input
5 4 4
i loser am the second
100 1 1 5 10
1 1
1 3
2 2 5
1 4
i am the second
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
	ll n,m,k;
	in(n),in(k),in(m);
	unordered_map<string, int> un;
	string s;

	for(int i = 0;i<n;i++){
		cin>>s;
		un.insert({s,i});
	}

	ll a[n];
	for(int i = 0;i<n;i++){
		in(a[i]);
	}
	for(int i = 0;i<k;i++){
		int x;
		cin>>x;
		ll f[x];
		ll mn = INT_MAX;
		for(int j = 0;j<x;j++){
			
			in(f[j]);
			mn = min(mn,f);
		}
		for(int j = 0;j<x;j++){
			a[f[j]] = mn;
		}

	}
	ll answer = 0;
	for(int i = 0;i<m;i++){
		cin>>s;
		answer = answer + a[un[s]];
	}
	cout<<answer;
	return 0;
}