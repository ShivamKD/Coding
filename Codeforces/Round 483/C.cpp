/*input
2
6 12 10
5 52 10
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
	while(n--){
		ll num,den,base;
		cin>>num>>den>>base;

		if(num==0){
			cout<<"Finite\n";
			return 0;
		}
		ll g = __gcd(num,den);
		num /= g;
		den /= g;
		if(den==1){
			//cout<<"Finite\n";
			//continue;
		}
		ll rem = num % den;
		if(rem == 0){
			cout<<"Finite\n";
			continue;
		}

		

		
		

		ll x = __gcd(base,den);
		if(x==1){
			cout<<"Infinite\n";
			continue;
		}
		else{
			cout<<"Finite\n";
			continue;
		}


		
	}
	
	return 0;
}