/*input
7 0
3 7 5 1 10 3 20
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n;
	int k;
	cin>>n>>k;
	vector<ll> vec;
	for (int i = 0; i < n; ++i)
	{
		ll x;
		cin>>x;
		vec.push_back(x);
	}
	sort(vec.begin(),vec.end());
	k = k - 1;
	ll ans = vec[k];
	if(k==-1){
		if(vec[0]==1){
			cout<<"-1";
		}
		else{
			cout<<"1";
		}
		return 0;
	}
	if(k==n-1){
		cout<<ans;
		return 0;
	}

	if(vec[k]==vec[k+1]){
		cout<<"-1";
		return 0;
	}

	cout<<ans;

	return 0;
}