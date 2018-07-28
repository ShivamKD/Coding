/*input
6
10 8 9 11 13 5
010010011101
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n;
	cin>>n;
	vector< pair<ll,ll> > vec;
	ll x;
	for(int i = 0;i<n;i++){
		cin>>x;
		vec.push_back({x,i+1});
	}

	sort(vec.begin(),vec.end());
	int both_empty = 0;

	string s;
	cin>>s;
	
	stack< pair<ll,ll> > st;
	

	for(int i = 0;i<2*n;i++){

		if(s[i]=='0'){
			cout<<vec[both_empty].second<<" ";
			st.push(vec[both_empty]);
			both_empty++;
		}
		else{
			pair<ll,ll> pr = st.top();
			st.pop();
			cout<<pr.second<<" ";
		}

	}
	return 0;
}