/*input
2
5 5
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
	cin>>n;
	ll a[n];
	map<ll,ll> mp[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		ll dup = a[i];
		for(int j = 2; j*j<=dup;j++){
			if(dup%j==0){
				mp[i][j]++;
				dup = dup / j;
				j--;
			}
		}
		if(dup>1){
			mp[i][dup]++;
		}
	}

	int answer[n+1];
	memset(answer,0,sizeof(answer));
	for(int i = 0;i<n;i++){
		int flag = 0;
		map<ll,ll> current = mp[i];
		for(auto itr : current){
			if(itr.second%2!=0){
				flag = 0;
				break;
			}
		}
		if(flag){
			a[1]++;
		}

		for(int j = i+1;j<n;j++){
			for(auto itr : mp[j]){
				current[itr.first]+=itr.second;
			}
			flag = 1;
			for(auto itr : current){
				if(itr.second % 2 != 0){
					flag = 0;
					break;
				}
			}
			if(flag){
				answer[j - i + 1]++;
			}
		}
	}

	for(int i = 1;i<=n;i++){
		cout<<answer[i]<<" ";
	}
	
	return 0;
}