/*input
1000000000 324934 1000 1000
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
	
	ll n,k,m,d;
	cin>>n>>k>>m>>d;
	ll answer = 0;
	//answer = 
	
	if(n/m<=k){
		answer = m;

	}


	for(int i = 1;i<=d;i++){
		ll x = n / (k*i);
		if(x<=m){
			if(i<d){
				ll f = n / (k*i + 1);
				if(f<=m){
					answer = max(answer,max(x*i,f*(i+1)));
				}
			}
			answer = max(answer,x*i);
		}
	}
	cout<<answer;
	return 0;
}