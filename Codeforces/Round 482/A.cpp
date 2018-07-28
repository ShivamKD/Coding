/*input
7
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long	
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll n;
	cin>>n;
	n++;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n%2==0)
		cout<<n/2;
	else
		cout<<n;

	return 0;
}