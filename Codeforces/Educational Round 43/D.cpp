/*input

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
	int d[n];
	for(int i = 0;i<n;i++) cin>>d[i];

	int edges = d[n-1] +1
	int degree[edges+1];
	memset(degree,0,sizeof(degree));

	for(int i = 2;i<=edges;i++){
		
			vec.push_back({1,i});
		
			degree[1]++;
			degree[i] = 1;
	}
	int done[edges+1];
	memset(done,0,sizeof(done));
	done[1] = 1;
	int last = 0;
	for(int i = 0;i<n-1;i++){
		int curr = 0;
		for(int i = 2;i<=edges;i++){
			if(!done[i]){
				curr = i;
				break;
			}
		}

		
	}
	return 0;
}