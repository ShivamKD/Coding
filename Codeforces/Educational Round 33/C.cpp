#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll z;

bool visited[100000+1];

vector <  vector <int > > vec(100000+1);

void dfs(int source,ll a[])
{
    visited[source]=true;
    
    if(a[source]<z)
    z=source;
    
    for(int i=0;i<vec[source].size();i++)
    {
        if(!visited[vec[source][i]])
        {
            visited[vec[source][i]]=true;
            dfs(vec[source][i],a);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    
    ll a[n+1];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i+1];
    }
    
    
    int c,b;
    
    for(int i=0;i<m;i++)
    {
        cin>>c>>b;
        vec[c].push_back(b);
        vec[b].push_back(c);
    }
    
    
    
    
    memset(visited,false,sizeof(visited));
    
    ll ans=0;
    
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            z=a[i];
            dfs(i,a);
            ans+=z;
        }
    }
    
    
    
    cout<<ans;
	return 0;
}
