/*input
4
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

	cin>>n;

	n--;
	//ll p = 1LL<<33;// overflow
	//cout<<p<<endl;
	ll dp[50];
	dp[0] = 0;

	for(ll i = 1;i<50;i++){
		dp[i] = 2 * dp[i-1] + (1LL<<(i-1));
	}
	ll answer = 0;
	//cout<<n<<endl;

	for(ll mask = 50;mask>=0;mask--){
		if((1LL<<mask)&n){
			//cout<<((1<<mask)&n)<<" ";
			//cout<<mask<<endl;
			answer += dp[mask] + (1LL<<mask);
		}
	}

	cout<<answer;
	return 0;
}