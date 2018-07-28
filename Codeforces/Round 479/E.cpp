/*input
5 4
1 2
3 4
5 4
3 5
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

vector<int> vec[200010];
bool visited[200010];
set< pair<int,int> > comps[200010];
int size = 0;


void dfs(int source){
	

	visited[source] = true;

	for(int x : vec[source]){

		int a = source;
		int b = x;
		if(a>b)
			swap(a,b);

		comps[size].insert({a,b});

		if(!visited[x]){
			
			dfs(x);
		}
	}
}

int main(){
	int ans =0;
	FIO
	int n,m;
	cin>>n>>m;
	for(int i = 0;i<m;i++){
		int u,v;
		cin>>u>>v;
		vec[v].push_back(u);
		vec[u].push_back(v);
	}
	memset(visited,false,sizeof(visited));

	for(int i = 1;i<=n;i++){
		if(!visited[i]){
			
			dfs(i);
			size++;
		}
	}

	//cout<<size<<" ";

	for(int i = 0;i<size;i++){
		map<int,int> mp;

		for(pair<int,int> p : comps[i]){
			//cout<<p.first<<" "<<p.second<<"\n";
			mp[p.first]++;
			mp[p.second]++;
		}
		int flag = 1;

		for(auto itr : mp){

			if(itr.second!=2){
				flag = 0;
				break;
			}


		}

		if(0){
			for(pair<int,int> p : comps[i]){
				cout<<p.first<<" "<<p.second<<"\n";
			}
		}


		//cout<<comps[i].size()<<'\n';
		if(mp.size())
		ans += flag;
	}

	cout<<ans;
	return 0;
}