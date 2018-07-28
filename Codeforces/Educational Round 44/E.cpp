/*input
6 3 5
1 2 4 7 9 10
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1e9 + 7;


int main(){
	FIO
	ll n,k,d;
	cin>>n>>k>>d;
	ll a[n],b[n];

	for(int i = 0;i<n;i++){
		cin>>a[i];
		b[i] = a[i];
	}

	sort(a,a+n);

	
	ll possible[n];

	memset(possible,0,sizeof(possible));
	ll open[n],close[n];
	memset(open,0,sizeof(open));
	memset(close,0,sizeof(open));

	for(int i = 0;i<=n-k;i++){
		
		ll diff = a[i+k-1] - a[i];
		
		
		//cout<<diff<<" ";
		if(diff <= d){
			//cout<<i<<" "<<(i+k-1)<<"\n";
			open[i]++;
			close[i+k-1]++;
		}
	}
	//cout<<"\n";
	ll current = 0;

	for(int i =0;i<n;i++){
		current += open[i];
		possible[i] = current;
		current -= close[i];
		if(current==0 and (i+1)%k!=0){
			cout<<"NO";
			return 0;
		}
	}

	for(int i = 0;i<n;i++){
		//cout<<i<<" "<<possible[i]<<"\n";

		if(possible[i]==0){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";

	
	return 0;
}