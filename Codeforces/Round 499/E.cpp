/*input
3 10
10 20 30
*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;
int main(){
	FAST_IO

	ll n,k;
	cin>>n>>k;
	ll a[n];
	set<ll> s;

	for(int i = 0;i<n;i++){
		cin>>a[i];
		a[i] = a[i] % k;
		s.insert(a[i]);

	}



	ll b[2*k+1] = {0};

	set<ll> another;

	for(ll x : s){
		if(x!=0){
			if(k%x!=0){
				ll f = (x * ( k / x  + 1) ) % k;
				another.insert(f);
			}
		}
	}

	for(ll x: another){
		s.insert(x);
	}
	for(ll x : s){
		if(k%x!=0){
			cout<<k<<"\n";
			for(int i = 0;i<k;i++){
				cout<<i<<" ";
			}
			return 0;
		}
	}
	int flag = 1;
	while(flag){
		flag = 0;
		set<ll> an;
		for(ll x : s){

			ll i = x;

			if(b[i]==1){
				continue;
			}

			b[i] = 1;

			
			

			while(i <= k){

				if(b[i-x]){

					b[i%k] = 1;
					
					//b[i] = 1;
				}

				if(b[i])
				if(i+x > k){
					if(!b[(i+x)%k]){
						b[(i+x)%k] = 1;
						flag = 1;
						an.insert((i+x)%k);
					}
				}
				i++;
			}
			if(flag){
				for(ll mb : an){
					s.insert(mb);
				}
				break;
			}
		}
	}

	vector<int> sol;
	for(int i = 0;i<k;i++){
		if(b[i]){
			sol.push_back(i);
		}
	}

	cout<<sol.size()<<"\n";
	for(int x : sol){
		cout<<x<<" ";
	}
	
	return 0;
}