/*input
4 4
1 2 3 4
9 1 10 6
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll n,p;
	cin>>n>>p;
	vector<ll> a(n);
	ll k[p];
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(i!=0){
			a[i] += a[i-1];
		}
	}
	ll current = 0;

	for(int i = 0;i<p;i++){
		cin>>k[i];
		int index = lower_bound(a.begin(),a.end(),current + k[i]) - a.begin();
		current += k[i];

		//cout<<current<<" "<<a[index]<<" ";
		if(index!=n){
			if(a[index]==current)
			index++;
		}
		int left = n - index;
		if(left==0){
			current= 0;
			left = n;
		}
		
		cout<<left<<"\n";
	}

	return 0;
}