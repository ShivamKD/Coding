/*input
10 8
10 13 15 16 17 19 20 22 24 25
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

ll binaryU(ll vec[],ll n,ll item,int i){

	ll lower = i, high = n-1;
	ll ans = i;

	while(lower<=high){
		ll mid = (lower+high)/2;
		if(vec[mid]==item){
			return mid;
		}
		else if(vec[mid]<item){
			lower = mid + 1;
			ans = mid;
		}
		else{
			high = mid - 1;
		}

	}
	return ans;
}


int main(){
	ll n,u;
	in(n),in(u);

	ll vec[n];
	ll x;
	int count = 0;

	for(int i = 0;i<n;i++){
		in(x);
		vec[i] = x;
		
	}

	if(count==n-1){
		cout<<-1;
		return 0;
	}
	double ans = -1.00000;
	
	for(int i = 0;i<n;i++){
		int upper = binaryU(vec,n,vec[i] + u,i);
		//cout<<vec[i]+u<<" ";
		int lower = i + 1;
		//cout<<vec[upper]<<endl;
		if(i < lower && lower < upper){
			//cout<<lower<<" "<<i<<endl;
			ans = max(ans, (vec[upper]- vec[lower])*1.000000000000/(vec[upper] - vec[i]));
		}
	}
	/*

	for(int i = 1;i<n-1;i++){

		if(vec[i-1]+u>=vec[i+1]){
			ans = max(ans,(vec[i+1]-vec[i])*1.0000000000/(vec[i+1]-vec[i-1]));
		}
	}
*/
	cout<<setprecision(10);
	cout<<ans;
	return 0;
}