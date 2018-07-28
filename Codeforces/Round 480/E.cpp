/*input
15 3
9 11
11 8
7 9
9 14
12 8
10 7
1 14
1 5
12 15
10 3
5 2
13 15
4 13
6 4
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

vector<int> vec[1000010];

int parent[1000010],child[100010];
set<int> leaf;

void dfs(int current,int par){
	int count = 0;
	for(int x : vec[current]){
		if(x!=par){
			count++;
			parent[x] = current;
			dfs(x,current);
		}
	}
	
	child[current] = count;
	if(count==0){
		leaf.insert(current);
	}

}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;

	for(int i =1 ;i < n;i++){
		int u,v;
		cin>>v>>u;
		vec[u].push_back(v);
		vec[v].push_back(u);

	}

	dfs(n,0);
	set<int> solution;

	while(solution.size() < k){
		auto itr = leaf.begin();
		solution.insert(*itr);
		child[parent[*itr]]--;
		if(child[parent[*itr]]==0){
			leaf.insert(parent[*itr]);
		}

		leaf.erase(itr);	
	}

	for(int x : solution){
		cout<<x<<" ";
	}

	return 0;
}