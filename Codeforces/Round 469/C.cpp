/*input
0010100
*/
#include <bits/stdc++.h>
using namespace std;

#define in(x) scanf("%lld",&x)
#define ll long long

const ll MOD = 1e9 + 7;




int main(){
	string s;
	cin>>s;
	ll n = s.length();
	

	vector<ll> vec[n];
	queue<ll> One,zero;
	ll top = 0;
	ll prev = 0;

	for(ll i = 0;i<n;i++){

		if(s[i]=='0'){
			if(One.empty()){
				vec[top].push_back(i+1);
				zero.push(top++);
			}
			else{
				ll p = One.front();
				One.pop();
				vec[p].push_back(i+1);
				zero.push(p);
			}
		}
		else{
			if(zero.empty()){
				cout<<"-1";
				return 0;
			}


			ll p = zero.front();
			zero.pop();
			vec[p].push_back(i+1);
			One.push(p);
		}
	}

	if(!One.empty()){
		cout<<-1;
		return 0;
	}

	cout<<top<<"\n";
	for(int i = 0;i<top;i++){
		
		cout<<vec[i].size();

		for(int j = 0;j<vec[i].size();j++){
			cout<<" "<<vec[i][j];
		}

		cout<<"\n";
	}


	return 0;
}