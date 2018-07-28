/*input
6
4 8 6 3 12 9
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO

	vector<ll> vec;
	int n;
	cin>>n;
	ll a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];

	}

	vec.push_back(a[0]);
	a[0] = 0;
	int flag = 1;
	while(vec.size()!=n and flag){
		ll x = vec[0];
		for(int i = 0;i<n;i++){
			if(a[i]==x*3){
				vec.insert(vec.begin(),a[i]);
				
				a[i] = 0;
				break;
			}
			
		}
		x = vec[vec.size()-1];
		for(int i = 0;i<n;i++){
			if(x*2==a[i]){
				
				ve.push_back(a[i]);
				a[i]=0;
				break;
			}

		}
		flag = 0;
		for(int i = 0;i<n;i++){
			cout<<a[i]<<" ";
			if(a[i]!=0){
				flag = 1;
				break;
			}
		}
		cout<<"\n";
	}
	for(ll x: vec){
		cout<<x<<" ";
	}
	return 0;
}