/*input
12 1
abaabbaaabbb
*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;
int main(){
	FAST_IO
	int k,n;
	cin>>n>>k;
	string s;
	cin>>s;
	int h[27] = {0};
	for(int i = 0;i<n;i++){
		h[s[i]-'a' + 1]++;
	}
	int ans = 0;
	for(int i = 1;k!=0 and i <=26;i++){
		if(h[i]!=0){
			k--;
			ans += i;
			i++;
		}
	}

	if(k!=0){
		cout<<-1;
		return 0;
	}

	cout<<ans;
	return 0;
}