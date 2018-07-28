/*input
5
2 2 1 2 2
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define in(x) scanf("%lld",&x)
const ll MOD = 1e9 + 7;


int main(){
	ll n;
	in(n);
	ll a[n];
	ll sum = 0;
	ll curr = 0;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	for(int i = 0;i<n;i++){
		curr += a[i];
		if(curr>=(sum/2 + sum%2)){
			printf("%d\n", i+1);
			return 0;
		}
	}

	return 0;
}