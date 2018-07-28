/*input
5 6 1 1 3
2
5
3
3 4 2 3
1 3 5 4
3 3 5 3
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll n,m,stairsN,liftsN,speed;
	cin>>n>>m>>stairsN>>liftsN>>speed;

	vector<ll> stairs(stairsN);
	for(int i = 0;i<stairsN;i++) cin>>stairs[i];

	vector<ll> lifts(liftsN);
	
	for(int i = 0;i<liftsN;i++) cin>>lifts[i];

	sort(stairs.begin(),stairs.end());
	sort(lifts.begin(),lifts.end());

	int q;
	cin>>q;

	while(q--){

		int a,b,c,d;
		cin>>a>>b>>c>>d;

		if(a>c){
			swap(a,c);
			swap(b,d);
		}

		

		
		ll moves = INT_MAX;
		ll at = 0;

		if(liftsN){
			int index = lower_bound(lifts.begin(),lifts.end(),b) - lifts.begin();
		if(index==lifts.size()){

			moves = abs(lifts[lifts.size()-1]-b) + abs(lifts[lifts.size()-1]-d);
			//at = lifts[lifts.size-1];
		}
		else{
			ll f = abs(b-lifts[index]) + abs(d-lifts[index]);
			ll s = INT_MAX;

			if(index+1!=liftsN)
			s = abs(lifts[index+1 ] - b) + abs(lifts[index+1]-d);

			if(f<s){
				at = lifts[index];
				moves = f;
			}
			else{
				at = lifts[index+1];
				moves = s;
			}
			if(index){
				s = abs(lifts[index-1 ] - b) + abs(lifts[index-1]-d);
				moves = min(moves,s);
			}
		}

			ll div = abs(a-c)/speed + (abs(a - c) % speed!=0);
			moves += div;
		}

		ll amove = INT_MAX;
		ll aat = 0;


		if(stairsN){
			
			int index = lower_bound(stairs.begin(),stairs.end(),b) - stairs.begin();
			if(index == stairs.size()){
				amove = abs(stairs[stairsN-1] - b) + abs(stairs[stairsN-1]- d) + abs(a-c);
			}
			else{
				ll f = abs(stairs[index] - b) + abs(stairs[index]- d) + abs(a-c);
				ll s = INT_MAX;
				if(index+1!=stairsN)
				s = abs(stairs[index+1] - b) + abs(stairs[index+1]- d) + abs(a-c);

				amove = min(f,s);
				if(index){
					s = abs(stairs[index-1] - b) + abs(stairs[index-1]- d) + abs(a-c);
					amove = min(amove,s);
				}
			}
		}

		cout<<min(moves,amove)<<"\n";


	}
	return 0;
}