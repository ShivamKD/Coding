/*input
5
3 2 1 4 5
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x)
#define loop(start,end) for(ll var = start; var < end; var++)
#define arr(a,n) loop(0,n) in(a[var])
#define parr(a,n) loop(0,n) printf("%lld ", a[var]);
const ll MOD = 1e9 + 7;

const int sz = 2 * 100000 + 100;

typedef struct mergeSortTree{
	vector<ll> vec;

	mergeSortTree(){}

	int size(){
		return vec.size();
	}

	void push(int x){
		vec.push_back(x);
	}

} MST;

MST tree[sz * 4];
ll a[sz];

MST merge(MST a, MST b){
	MST c;

	int x = a.size(), y = b.size();

	int i = 0, j = 0;
	while(i < x && j < y){
		if(a.vec[i] < b.vec[j]){
			c.push(a.vec[i++]);
		}
		else{
			c.push(b.vec[j++]);
		}
	}


	while(i < x){
		c.push(a.vec[i++]);
	}

	while(j<y){
		c.push(b.vec[j++]);
	}

	return c;
}


void build(ll low, ll high, ll pos){
	if(low==high){
		tree[pos].push(a[low]);
		return ;
	}

	if(low>high){
		return ;
	}

	ll mid = low + high;
	mid /= 2;

	build(low,mid,pos*2);
	build(mid+1,high,pos*2+1);

	tree[pos] = merge(tree[pos*2],tree[pos*2+1]);
}


ll query(ll qlow,ll qhigh,ll low, ll high,ll pos,ll x){

	if(qlow>high || qhigh<low || low > high || qlow>qhigh){
		return 0;
	}

	if(qlow <= low && high <= qhigh){

		return tree[pos].size() - (lower_bound(tree[pos].vec.begin(),tree[pos].vec.end(),x) - tree[pos].vec.begin());

	}

	ll mid = (low + high ) / 2;

	return query(qlow,qhigh,low,mid,pos*2,x) + query(qlow,qhigh,mid+1,high,pos*2+1,x);
}


int main(){

	ll n;
	cin>>n;

	for(int i = 1;i <= n;i++){
		in(a[i]);
	}

	build(1,n,1);

	ll answer = 0;

	for(ll i = 1;i<n;i++){
		answer += query(i + 1,min(a[i],n), 1, n, 1, i);
	}

	cout<<answer;
	return 0;
}