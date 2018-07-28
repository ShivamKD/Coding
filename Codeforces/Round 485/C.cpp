/*input
10
1 2 3 4 5 6 7 8 9 10
10 13 11 14 15 12 13 13 18 13
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n;
	cin>>n;
	ll a[n],b[n];
	for(int i = 0;i<n;i++)cin>>a[i];
	for(int i = 0;i<n;i++)cin>>b[i];


	ll out[n] = {0};
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(a[i]<a[j]){
				if(out[j]==0){
					out[j] = b[i] + b[j];

				}
				else{
					out[j] = min(out[j],b[i]+b[j]);
				}
			}
		}
	}

	ll ans = LLONG_MAX;
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			if(a[i]<a[j] and out[i]){
				ans = min(ans,out[i]+b[j]);
			}
		}
	}

	if(ans==LLONG_MAX){
		ans = -1;
	}
	cout<<ans;
	return 0;
}