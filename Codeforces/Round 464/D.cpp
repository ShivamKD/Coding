/*input
3
abb
dad
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;



//MoHib85
struct DisjointSetUnion
{
	int *deg;
	int *parent;
	DisjointSetUnion(int n)
	{
		deg = (int*)malloc(n*sizeof(int));
		parent = (int*)malloc(n*sizeof(int));

		for(int i = 0; i < n; i++)
		{
			deg[i] = 1;
			parent[i] = i;
		}
	}

	int getParent(int x)
	{
		if(x!=parent[x]){
			return (parent[x] = getParent(parent[x]));
		}
		return x;
	}

	void Union(int a,int b){
		int x = getParent(a);
		int y = getParent(b);
		if(x==y)
			return ;

		if(deg[x]>deg[y]){
			parent[y] = x;
			deg[x] += deg[y];
		}
		else {
			parent[x] = y;
			deg[y] += deg[y];
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    
    string a,b;
    cin>>a;
    cin>>b;

    DisjointSetUnion dsu(30);
    vector<pair<char,char> > answer;

    for(int i = 0;i<n;i++)
    {
    	if(dsu.getParent(a[i]-'a') == dsu.getParent(b[i]-'a'))
    		continue;

    	answer.push_back(make_pair(a[i],b[i]));
    	dsu.Union(a[i]-'a',b[i]-'a');
    }

    cout<<answer.size()<<"\n";
    for(int i =0; i<answer.size();i++)
    	cout<<answer[i].first<<" "<<answer[i].second<<"\n";

	return 0;
}             