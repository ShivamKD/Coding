/*input
4 2 1
2 2 1 2 3 2 2 3
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll n,k,l;
	cin>>n>>k>>l;
	ll a[n*k];
	for(int i = 0;i<n*k;i++){
		cin>>a[i];
	}

	sort(a,a+n*k);
	ll first = a[0];
	int last = 0;

	for(int i = 1;i<n*k;i++){
		if(a[i] - first > l){
			break;
		}
		last++;
	}


	if(last>=n-1){
		int f = 0;
		ll vol = 0;
		while(last + 1 - f * k + f >= n  and f < n){
			f++;
		}
		f--;
		n--;
		int start = k;
		vol = a[0];
		//cout<<f<<" "<<last<<" ";
		while(f and n){
			vol += a[start];
			start += k;
			f--;
			n--;
		}

		while(n){
			//cout<<"Not HEre";
			vol += a[last];
			last--;
			n--;
		}
		cout<<vol;
	}
	else{
		cout<<0;
		return 0;
	}


	return 0;
}