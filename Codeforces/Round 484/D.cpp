/*input
7
1 7 9 4 5 10 2 3
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

struct DisjointSet{
	ll parent[100010],degree[100010],maximum[100010];
	multiset<ll> components;

	DisjointSet(int n){
		for(int i = 1;i<=n;i++){
			parent[i] = i;
			maximum[i] = i;
			degree[i] = 1;
		}
	}

	ll getParent(ll x){
		if(x!=parent[x])
			return parent[x] = getParent(parent[x]);

		return x;
	}
	void Union(ll a,ll b){
		ll x = getParent(a);
		ll y = getParent(b);

		if(x==y){
			return ;
		}

		components.erase(parent[x]);
		components.erase(parent[y]);
		if(degree[x]>degree[y]){
			degree[x] += degree[y];
			components.insert(parent[x]);
			parent[y] = parent[x];
			maximum[x] = max(maximum[x],maximum[y]);
			
		}
		else{
			degree[y] += degree[x];
			components.insert(parent[y]);
			parent[x] = parent[y];
			maximum[y] = maximum[x],maximum[y];
		}
	}
};

int main(){
	FIO
	int n;
	cin>>n;
	ll b[n];
	vector<pair<ll,ll> > a(n);
	for(int i = 0;i<n;i++) {
		cin>>a[i].first;
		a[i].second = i+1;
		b[i] = a[i].first;
	}

	sort(a.begin(),a.end());

	DisjointSet dsu(n);
	dsu.components.insert(a[0].first);
	bool done[n+2];
	memset(done,false,sizeof(done));

	done[a[0].second] = true;

	ll current = 1;
	ll ans = a[0].first+1;
	//cout<<ans<<"\n";
	for(int i = 1;i<n;i++){
		set<ll> p;
		for(auto itr : dsu.components ){
			p.insert(dsu.degree[(ll)(itr)]);
			if(p.size()>1)
				break;
		}
		if(p.size()==1){
			if(dsu.components.size()>current){
				//cout<<p.size()<<"\n";
				//cout<<dsu.components.size()<<"\n";
				current = dsu.components.size();
				ans = a[i].first;
			}
		}

		dsu.components.insert(a[i].first);
		if(done[a[i].second + 1]){
			dsu.Union(a[i].second,a[i].second + 1);
		}
		if(done[a[i].second - 1]){
			dsu.Union(a[i].second,a[i].second - 1);
		}

		done[a[i].second] = true;


		if(i<n-1 and a[i+1].first!=a[i].first+1){
			p.clear();
			for(auto itr : dsu.components ){
				p.insert(dsu.degree[(ll)(itr)]);
				if(p.size()>1)
					break;
			}
			if(p.size()==1){

				if(dsu.components.size()>current){
					//cout<<dsu.components.size()<<"\n";
					current = dsu.components.size();
					ans = a[i].first + 1;
				}
			}
		}

	}

	cout<<ans;

	
	return 0;
}