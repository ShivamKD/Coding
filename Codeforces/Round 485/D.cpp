/*input
5 5 4 3
1 2 4 3 2
1 2
2 3
3 4
4 1
4 5
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1e9 + 7;

ll n,m,k,s;
set<ll> a[102];
vector<ll> vec[100010];
set<ll> p[100010];
ll c;
ll ans[100010];


ll aka[100010][102];



int main(){
	FIO
	ll val[100010];

	for(int i = 0;i<100010;i++) 
		for(int j = 0;j<102;j++) aka[i][j] = INT_MAX;
	
	cin>>n>>m>>k>>s;

	for(int i = 1;i<=n;i++){
		int x;
		cin>>x;
		val[i] = x;
		a[x].insert(i);
		aka[i][x] = 0;
	}

	for(int i = 0;i<m;i++){
		ll u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	bool done[100010];

	for(int i = 1;i<=k;i++){
		queue<int> q;
		for(int x : a[i]){
			q.push(x);
			aka[x][i] = 0;
		}
		while(!q.empty()){
			int next = q.front();
			q.pop();

			for(int x : vec[next]){
				if(aka[next][i] + 1 < aka[x][i]){
					aka[x][i] = aka[next][i] + 1;
					q.push(x);
				}
			}
		}
	}

	for(int i = 1;i<=n;i++){
		sort(aka[i],aka[i] + k+1);
		ll ans = 0;
		for(int j = 0;j<s;j++){
			//cout<<aka[i][j]<<" ";
			ans += aka[i][j];
		}
		cout<<ans<<" ";
	}
	return 0;
}