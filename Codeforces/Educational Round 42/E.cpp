/*input
4
-5 R
0 P
3 P
7 B
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define in(x) scanf("%lld",&x)
const ll MOD = 1e9 + 7;


ll merge(vector<ll> a, vector<ll> b){

	if(a.size()==0 || b.size()==0)
		return 0;

	ll answer = LLONG_MAX;

	int i = 0, j = 0;
	int prev = 0;

	while(i < a.size() && j < b.size()){
		if(a[i]<b[j]){
			if(prev==2){
				answer = min(answer,a[i] - b[j-1]);
				
			}
			prev = 1;
			i++;
		}
		else{
			if(prev==1){
				answer = min(answer,b[j] - a[i-1]);
			}
			prev = 2;
			j++;
		}
	}

	while(i<a.size()){
		if(prev==2){
			answer = min(answer,a[i] - b[j-1]);
		}
		break;
	}
	while(j<b.size()){
		if(prev == 1){
			answer = min(answer,b[j] - a[i-1]);
		}
		break;
	}

	return answer;
}

int main(){
	FIO;
	int n;
	cin>>n;
	vector<ll> r,b,p;

	ll x;
	char y;
	for(int i = 0;i<n;i++){
		cin>>x>>y;
		if(y=='R'){
			r.push_back(x);
		}
		else if(y=='B'){
			b.push_back(x);
		}
		else{
			p.push_back(x);
		}
	}
	sort(r.begin(),r.end());
	sort(b.begin(),b.end());
	sort(p.begin(),p.end());;

	ll answer = 0;

	if(p.size()){
		if(r.size()){
			answer += abs(max(r[r.size()-1],p[p.size()-1]) - min(r[0],p[0]));
		}

		if(b.size()){
			answer += abs(max(b[b.size()-1],p[p.size()-1]) - min(b[0],p[0]));
		}
	}
	else{
		if(r.size()){
			answer += abs(r[r.size()-1] - r[0]);
		}

		if(b.size()){
			answer += abs(b[b.size()-1] - b[0]);
		}
	}



	printf("%lld\n", answer);

	return 0;
}