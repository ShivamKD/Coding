/*input
12 5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;


#define in(x) scanf("%lld",&x);

int main(){
	

	ll a,b;
	in(a);
	in(b);
	int flag = 1;
	while(a && b && flag){
		
		flag = 0;
		if(a >= (2 * b)){
			a = a % (2*b);
			flag = 1;
		}

		if( b>=(a*2)){
			b = b % (2*a);
			flag = 1;
		}

	}

	printf("%lld %lld\n",a,b );
	return 0;
}