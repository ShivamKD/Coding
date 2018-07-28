/*input
0 1 1 0 0 0 0 0 0 7 0 0 0 0
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;
ll a[14];

int main(){
	FIO
	ll n;
//	ll a[14];
	for(int i =0;i<14;i++){
		cin>>a[i];
	}
	ll even = 0;
	ll ans = 0;
	for(int i = 0;i<14;i++){
		ll current = a[i];
		ll all = current / 14;
		ll b[14];
		for(int j = 0;j<14;j++){
			if(j==i){
				b[j] = all;
				continue;
			}
			b[j] = a[j] + all;
		}

		ll rem = current  % 14;
		for(int j = 0;j<rem;j++){
			b[(i+1+j)%14]++;
		}
		current = 0;

		for(int j =0;j<14;j++){
			//cout<<b[j]<<" ";
			if(b[j]%2==0){
				current+=b[j];
			}
		}
		//cout<<"\n";

		ans = max(ans,current);
	}
	cout<<ans;
	return 0;
}