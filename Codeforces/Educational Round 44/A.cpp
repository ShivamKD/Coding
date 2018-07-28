/*input
6
1 2 6
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
	int a[n];

	for(int i = 0;i<n/2;i++){
		cin>>a[i];
	}
	sort(a,a+n/2);
	int ans = 0,ans1 = 0;
	for(int i = 1;i<n;i+=2){
		//cout<<a[i/2]<<" "<<i<<" "<<abs(a[i/2]-i)<<"\n";
		ans += abs(a[i/2]-i);
		ans1 += abs(a[i/2]-(i+1));
	}

	cout<<min(ans,ans1);


	return 0;
} 