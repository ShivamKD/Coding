/*input
6 60
0 0
1 20
3 21
5 0
19 30
23 40
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int diff(pair<int,int> a,pair<int,int> b){
	int answer = 0;
	//cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second<<"\n";

	if(b.second<a.second){
		answer = b.second + 60 - a.second;
		b.first--;
	}
	else
		answer = b.second - a.second;

	answer = answer + (b.first - a.first) * 60;
	return answer;
}



int main(){
	FIO
	int n,s;
	vector<pair<int,int> > vec;
	cin>>n>>s;
	for(int i = 0;i<n;i++){
		int x,y;
		cin>>x>>y;
		vec.push_back({x,y});
	}

	int h = 0, m = 0;

	if(diff({0,0},vec[0])>=s){
		//cout<<diff({0,1},vec[0])<<"\n";
		cout<<"0 0";
		return 0;
	}

	h = vec[0].first;
	m = vec[0].second;
	m = m + s + 1;
	if(m>=60){
		m = m - 60;
		h++;
	}
	for(int i = 1;i<n;i++){
		if(diff({h,m},vec[i])>s){
			cout<<h<<" "<<m;
			return 0;
		}
		h = vec[i].first;
		m = vec[i].second + s + 1;
		if(m>=60){
			m = m- 60;
			h++;
		}
	}
	cout<<h<<" "<<m;

	return 0;
}