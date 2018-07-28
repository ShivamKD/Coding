/*input
10 5
0 0 1 0 2 0 0 1 0

*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 7;

int main(){
	FIO 
	ll l,w;
	cin>>w>>l;
	ll a[w];
	for(ll i = 0;i<w-1;i++) cin>>a[i];

	ll current, answer;
	current = answer = 0;
	for(int i = 0;i<l;i++){
		current += a[i];
	}
	answer = current;
	//cout<<answer<<"\n";
	for(int i = l;i<w-1;i++){
		//cout<<i<<" "<<current<<"\n";
		current += (a[i] - a[i-l]);
		answer = min(answer,current);
		//cout<<i<<" "<<current<<"\n";
	}

	cout<<answer;

	return 0;
}