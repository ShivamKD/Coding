/*input
100 1
1
*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;
int main(){
	FAST_IO

	ll n,m;
	cin>>n>>m;
	
	int a[1000] = {0};
	int x;
	set<int> s;
	for(int i = 0;i<m;i++){
		cin>>x;
		a[x]++;
		s.insert(x);
	}

	vector<int> vec;
	for(int i = 0;i<=100;i++){
		if(a[i]){
			vec.push_back(a[i]);
		}
	}

	sort(vec.begin(),vec.end());

	int divs[vec.size()] = {0};

	for(int i = 0;i<n;i++){
		int f = 0;
		int p = -1;
		for(int j = 0;j<vec.size();j++){
			int curr = vec[j] / (divs[j] + 1);
			if(curr > f){
				f = curr;
				p = j;
			}
		}

		if(p==-1){
			cout<<0;
			return 0;
		}

		divs[p]++;
	}
	int ans = INT_MAX;
	for(int i = 0;i<vec.size();i++){
		if(divs[i]!=0){
			ans = min(ans, vec[i]/divs[i]);
		}
	}

	cout<<ans;

	return 0;
}