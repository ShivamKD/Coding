/*input
4 3 4
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll a,b,k;
	cin>>a>>b>>k;
	ll x = 1, y = 1;

	if(k<a){
		x = k + 1;
		cout<<x<<" "<<y;
		return 0;
	}
	k = k - (a - 1) ;
	ll rem  = k % (b-1);
	ll p = k / (b-1) + (rem!=0);
	x = a - p + 1;
	//cout<<p;
	if(p%2){
		y = rem;
		if(y==0)
			y = b - 1;
		y++;
	}
	else{
		//cout<<"Here";
		y = b - rem;
		if(rem==0)
			y = 1;
		y++;
	}

	printf("%lld %lld\n", x,y);
	return 0;
}