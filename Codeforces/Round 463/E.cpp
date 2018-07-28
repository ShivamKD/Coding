/*input
3 2
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

string toBinary(ll n){
	string ret = "";
	while(n){
		if(n%2)
			ret = "1" + ret;
		else
			ret = "0" + ret;
		n = n>>1;
	}
	return ret;
}

ll power(ll x,ll y){
	ll res = 1;
	if(x== 0)
		return 0;

	while(y>0){
		if(y&1)
			res = (res * x) % MOD;

		y = y>>1;
		x = (x * x) % MOD;
	}

	return res;
}

int main(){
	ll n,k;
	cin>>n>>k;
	string s = toBinary(n);
	n = s.length();
	int h[n+1] = {0};
	int count = 0;
	for(int i = 0;i<n;i++){
		if(s[i]=='1'){
			int left = n - 1 -i;

			ll c = 0;
			ll val = 1;
			for(int j = 1;j<=left;j++){
				val *= (left - j + 1)/j;
				h[count+j]+=val;
			}
			count++;
			h[count]++;
		}

	}
	ll answer = 0;

	for(int i = 1;i<=n;i++){
		answer += h[i] * power(i,k);
		answer %= MOD;
	}
	cout<<answer;
	return 0;
}