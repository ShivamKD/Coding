/*input
a
a

*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;
int main(){
	FAST_IO

	string a,b;
	cin>>a;
	cin>>b;
	int i,j;
	i = a.length()-1;
	j = b.length()-1;

	while(i >= 0 && j>=0 && a[i]==b[j]){
		i--;j--;
	}

	cout<<(i+j+2);

	return 0;
}