/*input
5 5
1 2
3 4
3 2
4 2
2 5
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%d",&x)

const int mx = 200010;

set<int> all;
set<int> graph[mx];
vector<int> solution;


int size = 0;

void dfs(int source){

	size++;
	all.erase(source);
	
	for(set<int>::iterator itr = all.begin();itr!=all.end();itr++){
		if(graph[source].find(*itr) == graph[source].end()){
			dfs(source);
			
		}


		if(all.size()==0)
			return ;
	}

}
int n,m;
int u,v;

int main(){
	in(n);
	in(m);

	for(int i = 0; i < m;i++){
		in(u);in(v);
		graph[u].insert(v);
		graph[v].insert(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		/* code */
		all.insert(i);
	}

	for(int i = 1;i<=n;i++){
		if(all.find(i)!=all.end()){
			size = 0;
			dfs(i);
			solution.push_back(size);
		}

		if(all.size()==0)
			break;
	}

	printf("%d\n",(int)solution.size() );
	for (int i = 0; i < solution.size(); ++i)
	{
		/* code */
		printf("%d ",solution[i] );
	}

	return 0;
}