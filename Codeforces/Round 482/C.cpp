/*input
6 1 2
1 2
2 3
2 4
4 5
4 6
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;


set<int> vec[300110];

ll done[300110];
vector<int> path;

int found(int source,int parent,int destination){

	for(int x : vec[source]){
		if(x!=parent){
			if(x==destination){
				path.push_back(x);
				return 1;
			}
			int b = found(x,source,destination);
			if(b){
				path.push_back(x);
				return 1;
			}
		}
	}
	return 0;
}

ll coun = 0;

void dfs(int current,int parent){
	coun++;
	for(int x : vec[current]){
		if(x!=parent){
			dfs(x,current);
		}
	}
}

int main(){
	FIO
	int n,x,y;
	int root = 0;
	cin>>n>>x>>y;
	for(int i = 0;i<n;i++){
		int u,v;
		cin>>u>>v;
		vec[u].insert(v);
		vec[v].insert(u);
		
	}
	
	ll ans = 1LL * n * (n - 1);
	//cout<<ans<<" ";
	memset(done,0,sizeof(done));

	//path.push_back(x);
	found(x,0,y);
	path.push_back(x);
	for(int i = 1;i<path.size();i++){
		//cout<<"Here\n";
		//cout<<path[i]<<"-path\n";
		auto itr = vec[path[i-1]].find((path[i]));
		//cout<<*itr<<" ";
		vec[path[i-1]].erase(itr);
		itr = vec[path[i]].find((path[i-1]));
		//cout<<*itr<<"\n";
		vec[path[i]].erase(itr);
	}
	dfs(x,0);
	ll a  = coun ;
	//cout<<a<<" ";
	coun = 0;
	dfs(y,0);
	a = a * coun;
	//cout<<a<<" ";

	ans = ans - a;
	cout<<ans<<"\n";

	//cout<<*vec[3].begin();
	return 0;
}