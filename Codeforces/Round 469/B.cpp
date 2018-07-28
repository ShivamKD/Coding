/*input
3 3
1 10 100
1 100 10
*/
#include <bits/stdc++.h>
using namespace std;

#define in(x) scanf("%lld",&x)
#define ll long long

const ll MOD = 1e9 + 7;




int main(){

	ll n,m;
	in(n);
	in(m);

	ll a[n],b[m];
	for (int i = 0; i < n; ++i)
	{
		in(a[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		/* code */
		in(b[i]);
	}

	ll i,j;

	i = j = 0;

	ll count = 0;
	ll aSum = 0,bSum = 0;

	while(i<n && j<m){

		if(aSum>bSum){
			bSum += b[j];
		}
		else if(aSum<bSum){
			aSum += a[i];
		}
		else{
			aSum+=a[i];
			bSum += b[j];
		}
		

		//cout<<aSum<<" "<<bSum<<"\n";

		if(aSum == bSum){
			//cout<<i<<" "<<j<<"\n";
			count++;
			aSum = 0;
			bSum = 0;
			i++;
			j++;
		}
		else if(aSum>bSum){
			j++;
		}
		else{
			i++;
		}
	}
	
	
	cout<<count;
	return 0;
}