/*input
6 3
1 3 5 2 5 4
1 1 0 1 0 0
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
	ll n,k;
	cin>>n>>k;
	ll a[n];

	for(int i = 0;i<n;i++){
		cin>>a[i];
	}

	ll t[n];
	ll temp[n+5];
	ll start[n+1];

	ll pre[n+2];
	pre[0] = 0;
	start[0] = 0;

	for(ll i = 0;i<n;i++){
		cin>>t[i];

		pre[i+1] = a[i] + pre[i];

		if(t[i]){
			start[i+1] = a[i] + start[i];
		}
		else{
			start[i+1] = start[i];
		}
	}
	pre[n+1] = pre[n];

	temp[n+1] = temp[n+2] = temp[n+3] = 0;
	
	for(int i = n-1;i>=0;i--){

		if(t[i]){
			temp[i+1] = a[i] + temp[i+2];
		}
		else{
			temp[i+1] = temp[i+2];;
		}

	}

	ll answer = 0;

	for(int i = 0;i<=n-k+1;i++){
		//cout<<start[i]<<" ";
		answer = max(answer,start[i] + pre[i+k] - pre[i] + temp[i+k+1]);
	}
	cout<<answer;
	return 0;
}