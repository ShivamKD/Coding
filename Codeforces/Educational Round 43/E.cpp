/*input
2 2 1
501 600
500 100
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll n,a,b;
	cin>>n>>a>>b;
	
	ll p = 1;
	for(int i = 1;i<=a;i++){
		p = p *2;
	}

	ll health[n],damage[n];
	ll max_i = -1;
	ll max_val = LLONG_MIN;

	for(int i = 0;i<n;i++){

		cin>>health[i]>>damage[i];

		if((health[i] * p - damage[i]) >= max_val){
			max_val = health[i] * p - damage[i];
			max_i = i;
		}

	}
	//cout<<max_i<<"\n";
	
	health[max_i] = health[max_i] * p;
	//cout<<health[max_i]<<"\n";
	vector < pair<ll,ll> > vec;

	for (int i = 0; i < n; ++i)
	{
		vec.push_back({ damage[i] - health[i],i});
	}

	sort(vec.begin(),vec.end());

	for(int i = 0;i<min(n,b)  ;i++){
		
		//if(damage[vec[i].second] <= health[vec[i].second])
		damage[vec[i].second] = health[vec[i].second];
		//else
		//	b++;
	}

	ll answer = 0;

	for(int i =0;i<n;i++){
		answer += damage[i];
	}

	cout<<answer;
	return 0;
}