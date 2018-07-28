/*input
4
1 1 1 1023
*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;
int main(){
	FAST_IO
	ll n;
	cin>>n;
	unordered_map<ll,vector<ll> > mp;
	bool done[n];
	memset(done,false,sizeof(done));

	ll a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		mp[a[i]].push_back(i);
	}

	for(int i = 0;i<n;i++){
		for(ll j = 0; j < 32;j++){
			if( a[i] < (1<<j)){
				ll rem = (1<<j) - a[i];
				//cout<<rem<<" ";
				if(rem == a[i]){
					if(mp[a[i]].size() > 1){
						mp[a[i]].clear();
						break;
					}
				}
				else if(mp.find(rem)!=mp.end()){
					//cout<<"Here";
					mp[rem].clear();
					mp[a[i]].clear();
					break;
				}
			}
		}
	}

	int ans = 0;
	for(auto itr : mp){
		ans += itr.second.size();
	}
	cout<<ans;

	return 0;
}