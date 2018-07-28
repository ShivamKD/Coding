/*input
6
1 2 4 8 16 32
4
1 6
2 5
3 4
1 2
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

ll tree[5010][5010];

void build(int i,ll a[],int start,int end,int pos){
	if(start==end){
		tree[i][pos] = a[start];
		//cout<<i<<" "<<a[start]<<"\n";
		return ;
	}
	int mid = (start+end)/2;
	build(i,a,start,mid,pos*2);
	build(i,a,mid+1,end,pos*2+1);
	tree[i][pos] = max(tree[i][pos*2],tree[i][pos*2+1]);
}

ll query(int i,int qlow,int qhigh,int low,int high,int pos){
	
	if(qlow > high or qhigh < low or low > high){
		return 0;
	}

	if(qlow <= low and high <= qhigh){
		return tree[i][pos];
	}
	int mid = (low+high)/2;
	
	return max(query(i,qlow,qhigh,low,mid,pos*2),query(i,qlow,qhigh,mid+1,high,pos*2+1));

}

int main(){
	FIO
	int n;
	cin>>n;
	ll a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}

	
	for(int i = 0;i<n;i++){
		ll ter[n+1];
		ter[1] =  a[i];
		for(int j = i+1;j<n;j++){
			ter[j-i+1] = a[j] ^ ter[j-i];
			//cout<<ter[j-i+1]<<" ";
		}
		build(i+1,ter,1,n-i,1);
		//cout<<"---------\n";
	}
	map<pair<int,int> ,ll> mp;
	int q;
	cin>>q;
	for(int i = 0;i<q;i++){
		int l,r;
		cin>>l>>r;
		if(mp.find({l,r})==mp.end()){
			ll ans = 0;
			for(int x = l; x<=r;x++){
				ans = max(query(x,1,r-x+1,1,n-x+1,1),ans);
			}
			mp.insert({{l,r},ans});
			cout<<ans;
		}
		else{
			cout<<mp[{l,r}];
		}
		cout<<"\n";
	}
	return 0;
}