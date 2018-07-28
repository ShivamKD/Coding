/*input
16
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
	ll n;
	in(n);
	if(n<6){
		cout<<"-1\n";
	}
	else{
		cout<<"1 2\n1 3\n1 4\n";
		for(ll j = 5;j<=n;j++){
			cout<<3<<" "<<j<<"\n";
		}
	}
	for(int i = 2;i<=n;i++){
		cout<<(i-1)<<" "<<i<<"\n";
	}
	return 0;
}