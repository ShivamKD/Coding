/*input
8
10010101
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
	string s;
	cin>>s;
	int first = s[0] - '0';
	int count = first;
	for(int i = 1;i<n;i++){

		if(s[i]=='1'){
			count++;
			if(s[i-1]=='1'){
				cout<<"No";
				return 0;
			}
		}
	}
	if(count== (n/2 + n%2)){
		cout<<"Yes";
	}
	else
		cout<<"No";
	return 0;
}