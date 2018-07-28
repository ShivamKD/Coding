/*input
3 9
1 1 2 2 2 3 1 2 3
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
	int n,m;
	cin>>n>>m;
	int x;
	int h[n+1] = {0};
	for(int i = 0;i<m;i++){
		cin>>x;
		h[x]++;
	}

	int mn = 100000, mx = 0;

	for(int i = 1;i<=n;i++){
		mn = min(mn,h[i]);
		mx = max(mx,h[i]);
	}
	cout<<mn;
	return 0;
}