/*input
1000000000 9
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n,k;
	cin>>n>>k;
	while(k){
		

		if(n%10==0){
			n = n / 10;
			k--;
			continue;
		}
		n--;
		//cout<<n<<" ";
		k--;
	}
	cout<<n;

	return 0;
}