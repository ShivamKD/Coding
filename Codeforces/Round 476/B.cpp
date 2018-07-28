/*input
19 6
##..............###
#......#####.....##
.....#########.....
....###########....
...#############...
..###############..
.#################.
.#################.
.#################.
.#################.
#####....##....####
####............###
####............###
#####...####...####
.#####..####..#####
...###........###..
....###########....
.........##........
#.................#
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 7;

int main(){
	FIO 
	int n,k;
	cin>>n>>k;
	string s[n];
	int a[n][n];
	for(int i = 0;i<n;i++){
		cin>>s[i];
		for(int j = 0;j<n;j++){
			if(s[i][j]=='#')
				a[i][j] = -1;
			else
				a[i][j] = 0;
		}
	}	

	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(i+k<=n){
				int flag = 0;
				for(int f = i;f<i+k;f++){
					if(s[f][j]=='#'){
						flag = 1;
						break;
					}
				}
				if(!flag){
					for(int f = i;f<i+k;f++){
						a[f][j]++;
					}
				}
			}

			if(j+k<=n){
				int flag = 0;
				for(int f = j;f<j+k;f++){
					if(s[i][f]=='#'){
						flag = 1;
						break;
					}
				}
				if(!flag){
					for(int f = j;f<j+k;f++){
						a[i][f]++;
					}
				}
			}
		}
	}
	int r = 1,c = 1;
	int val = 0;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(a[i][j]>val){
				r = i+1;
				c = j+1;
				val = a[i][j];
			}
		}
	}

	cout<<r<<" "<<c;
	return 0;
}