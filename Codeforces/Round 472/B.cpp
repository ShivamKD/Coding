/*input
2 2
.#
##
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x)
#define loop(start,end) for(ll var = start; var < end; var++)
#define arr(a,n) loop(0,n) in(a[var])
#define parr(a,n) loop(0,n) printf("%lld ", a[var]);
const ll MOD = 1e9 + 7;



int main(){
	int r,c;
	cin>>r>>c;
	string s[r];
	int g[r][c];
	memset(g,0,sizeof(g));
	vector<int> vec[r];
	for(int i = 0;i<r;i++){
		cin>>s[i];
		for(int j = 0;j<c;j++){
			if(s[i][j]=='#'){
				g[i][j] = 1;
			}
		}
	}

	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			if(g[i][j]==1){
				for(int k = i+1;k<r;k++){
					if(g[k][j] == g[i][j]){
						for(int l = 0;l<c;l++){
							if(g[i][l]!=g[k][l]){
								cout<<"No";
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout<<"Yes";
	return 0;
}