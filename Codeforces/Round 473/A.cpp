/*input
2
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
	if(n%2){
		cout<<"Ehab\n";
	}
	else{
		cout<<"Mahmoud\n";
;	}
	return 0;
}