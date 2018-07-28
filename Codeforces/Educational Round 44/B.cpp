/*input
3 4
1010
0100
1101
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n,m;
	cin>>n>>m;
	string s[n];
	for(int i = 0;i<n;i++){
		cin>>s[i];
	}

	set<int> p[n];
	int flag[m];
	memset(flag,0,sizeof(flag));

	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(s[i][j]=='1'){
				flag[j]++;
			}
		}
	}

	int count = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<m;j++){
			if(s[i][j]=='1'){
				flag[j]--;
			}
		}
		count = 0;
		for(int j = 0;j<m;j++){
			if(flag[j]){
				count++;
			}
		}
		if(count==m){
			cout<<"YES";
			return 0;
		}
		for(int j = 0;j<m;j++){
			if(s[i][j]=='1'){
				flag[j]++;
			}
		}

	}

	cout<<"NO";
	return 0;
}