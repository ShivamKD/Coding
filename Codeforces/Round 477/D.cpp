/*input
4 20 32
21 11 11 12

*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

bool sortinrev(const pair<ll,int> &a, 
               const pair<ll,int> &b){
       return (a.first > b.first);
}


int main(){
	FIO;

	ll n,a,b;
	cin>>n>>a>>b;
	int changed = 0;
	
	vector<pair<ll,int> > vec;
	set<int> all;
	for(int i = 0;i<n;i++){
		ll x;
		cin>>x;
		all.insert(i+1);
		vec.push_back({x,i+1});
	}

	sort(vec.begin(),vec.end(),sortinrev);

	set<int> k1,k2;
	int i;
	for(i = 0;i<n;i++){
		k1.insert(vec[i].second);
		if(vec[i].first >= (a * 1.00/ (k1.size()))){
			i++;
			break;
		}
	}
	//cout<<i<<"\n";

	int flag = 0;

	for(;i<n;i++){
		flag = 1;
		k2.insert(vec[i].second);
		if(vec[i].first >= (b * 1.0000 / k2.size())){
			break;
		}
	}
	//cout<<i<<"\n";

	if(flag and i!=n){
		cout<<"Yes\n";
		if(!changed){
		cout<<k1.size()<<" "<<k2.size()<<"\n";
		for(int x : k1){
			cout<<x<<" ";
		}
		cout<<"\n";
		for(int x : k2){
			cout<<x<<" ";
		}
	}
	else{
		cout<<k2.size()<<" "<<k1.size()<<"\n";
		for(int x : k2){
			cout<<x<<" ";
		}
		cout<<"\n";
		for(int x : k1){
			cout<<x<<" ";
		}
	}
	return 0;
	}
	else{
		swap(a,b);
		changed = 1;
		set<int> k1,k2;
		int i;
		for(i = 0;i<n;i++){
			k1.insert(vec[i].second);
			if(vec[i].first >= (a * 1.00/ (k1.size()))){
				i++;
				break;
			}
		}
		//cout<<i<<"\n";

		int flag = 0;

		for(;i<n;i++){
			flag = 1;
			k2.insert(vec[i].second);
			if(vec[i].first >= (b * 1.0000 / k2.size())){
				break;
			}
		}
		//cout<<i<<"\n";

		if(flag and i!=n){
			cout<<"Yes\n";
			if(!changed){
			cout<<k1.size()<<" "<<k2.size()<<"\n";
			for(int x : k1){
				cout<<x<<" ";
			}
			cout<<"\n";
			for(int x : k2){
				cout<<x<<" ";
			}
		}
		else{
			cout<<k2.size()<<" "<<k1.size()<<"\n";
			for(int x : k2){
				cout<<x<<" ";
			}
			cout<<"\n";
			for(int x : k1){
				cout<<x<<" ";
			}
		}

		}
		else{
			cout<<"No";
		}
	}
	return 0;
}