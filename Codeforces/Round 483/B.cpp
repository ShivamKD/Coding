/*input
2 4
*.*.
1211
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n,m;
	cin>>n>>m;
	string s[n];
	for(int i = 0;i<n;i++){
		cin>>s[i];
	}

	int a[n+2][m+2],b[n+2][m+2];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(s[i-1][j-1]=='*'){
				b[i][j] = 0;
				
				a[i][j+1]++;
				a[i][j-1]++;
				a[i+1][j]++;
				a[i+1][j+1]++;
				a[i+1][j-1]++;
				a[i-1][j]++;
				a[i-1][j+1]++;
				a[i-1][j-1]++;


			}
			else if(s[i-1][j-1]=='.'){
				b[i][j] = 0;
			}
			else{
				b[i][j] = s[i-1][j-1] - '0';
			}
		}
	}
	

	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if(s[i-1][j-1]!='*'){
				if(a[i][j]!=b[i][j]){
					//cout<<b[i][j]<<"\n";
					cout<<"NO";
					return 0;
				}
			}
		}
	}
	cout<<"YES";
	return 0;
}