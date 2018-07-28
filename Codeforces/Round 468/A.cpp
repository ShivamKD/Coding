/*input
101
99
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x);

const ll MOD = 1e9 + 7;

/*
fast INPUT
void in(int &x){
    char c = getchar_unlocked();
    while(c<'0' || c>'9')
    {
        c = getchar_unlocked();
    
    }
    x=0;
    while(c>='0' && c<='9')
    {
        x = 10 * x + c - 48;
        c = getchar_unlocked();
    }
}
*/



int main(){
	ll a,b;
	in(a);
	in(b);

	ll diff = abs(a-b);

	ll first = diff/2;
	ll second = diff - first;
	ll ans = first*(first+1)/2 + second * (second + 1)/2;

	printf("%lld\n",ans );
	return 0;
}
