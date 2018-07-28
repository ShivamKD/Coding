/*input

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;



// Faster Input
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


int main(){
	

	return 0;
}