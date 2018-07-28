/*input
5 2
2 1 5 3 4
*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;
int main(){
	FAST_IO

	int n,m;
	cin>>n>>m;
	int a[n];
	int p = 0;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(a[i]==m){
			p = i;
		}
	}
	int b[n] = {0};
	b[p] = 0;
	ll ans = 0;
	for(int j = p-1;j>=0;j--){
		if(a[j] < m){
			b[j] = b[j+1] -1;
		}
		else{
			b[j] = b[j+1] + 1;
		}
	}

	unordered_map<int,int> mp;

	for(int j = p + 1;j<n;j++){
		if(a[j] < m){
			b[j] = b[j-1] -1;
		}
		else{
			b[j] = b[j-1] + 1;
		}
		mp[b[j]]++;
	}

	for(int j = 0;j<p;j++){
		int rem = -b[j];
		if(rem==0)
			ans++;
		if(rem==-1){
			ans++;
		}
		//cout<<b[j]<<" "<<mp[rem]<<" "<<mp[rem+1]<<"\n";
		ans += mp[rem] + mp[rem+1];
	}
	ans += mp[0] + mp[1];
	cout<<ans+1;
	return 0;
}