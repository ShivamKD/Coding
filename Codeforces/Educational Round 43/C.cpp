/*input
3
1 5
2 6
3 4
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;


bool mycomp(pair<int, pair<int, int> > a, pair< int, pair<int, int> > b){
	if(a.first!=b.first)
		return a.first < b.first;

	return b.second.first < a.second.first;
}
int main(){
	FIO
	int n;
	cin>>n;
	vector< pair<int, pair<int,int> > > vec;
	for(int i = 0;i<n;i++){
		int x,y;
		cin>>x>>y;
		vec.push_back({x,{y,i+1}});

	}

	sort(vec.begin(),vec.end(),mycomp);
	for(int i = 0;i<n-1;i++){
		if(vec[i].second.first >= vec[i+1].second.first){
			cout<<vec[i+1].second.second<<" "<<vec[i].second.second;
			return 0;
		}
	}
	cout<<"-1 -1";
	
	return 0;
}