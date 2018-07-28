/*input
1
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
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}

	int count = 0;
	vector<int> p;
	for(int i = 1;i<n;i++){
		if(a[i]==1){
			p.push_back(a[i-1]);
		}

	}
	p.push_back(a[n-1]);
	cout<<p.size()<<"\n";
	for(int x : p){
		cout<<x<<" ";
	}

	return 0;
}