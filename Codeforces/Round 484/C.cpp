/*input
2
1 2
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;
vector<int> vec[100010];
int childs[100010];
int ans = 0;

void bfs(int source,int parent){
	childs[source] = 1;
	for(int x : vec[source]){
		if(x!=parent){
			bfs(x,source);
			childs[source]  +=  childs[x];
		}
		else{
			;//childs[source]++;
		}
	}
	//cout<<source<<" "<<childs[source]<<"\n";
	if(childs[source]!=0 and childs[source]%2==0){
		childs[source] = 0;
		ans++;
	}
}

int main(){
	FIO
	int n;
	cin>>n;
	if(n%2){
		cout<<"-1";
		return 0;
	}
	int v,u;
	for(int i = 1;i<n;i++){
		cin>>v>>u;
		vec[v].push_back(u);
		vec[u].push_back(v);
		childs[i] = 1;
	}
	childs[n] = 1;
	bfs(1,0);
	
	cout<<ans-1;
	return 0;
}