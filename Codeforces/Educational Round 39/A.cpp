/*input
3
1 -2 0
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;


#define in(x) scanf("%lld",&x);
// Faster Input
/*
void in(ll &x){

	char c = getchar_unlocked();
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
	}

	x = 0;

	while(c>='0' && c<='9'){
		x = x * 10 + c - '0';
		c = getchar_unlocked();
	}

}
*/

ll n;		

int main(){
	


	in(n);
	ll neg = 0;
	ll pos = 0;
	ll mn = INT_MAX;
	ll temp;

	for(int i = 0;i<n;i++){
		in(temp);
		if(temp>0){
			pos += temp;
		}
		else
			neg += temp;

		mn = min(mn,temp);
	}

	if(mn<0){
		printf("%lld\n", pos - neg);

	}
	else{
		printf("%lld\n",pos  );
	}

	return 0;
}