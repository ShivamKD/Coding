/*input
5
3 12
1 2 1
3 12
2 4 -1
3 8
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 7;

ll valueShifts[65];
ll noOfElements[65];

void init(){
	for(int i = 1;i<66;i++){
		noOfElements[i] = (1LL<<(i-1));
		valueShifts[i] = 0;
	}
}

ll X, level, choice, K;

ll atLevel(ll a){
	ll count = 0;
	while(a){
		a = a/2;
		//cout<<a<<" ";
		count++;
	}
	return count;
}

int main(){
	init();
	ll Q;
	in(Q);
	
	while(Q--){
	    
		in(choice);
		if(choice == 1){
			in(X);
			in(K);
			level = atLevel(X);
			K = K % noOfElements[level];
			K = ( K + noOfElements[level]) % noOfElements[level];
			valueShifts[level] = (valueShifts[level] + K) % noOfElements[level];
		}
		else if(choice == 2){
			in(X);
			in(K);
			level = atLevel(X);
			for(int i = level;i<65;i++){
			    K = K % noOfElements[i];
				K = (K + noOfElements[i]) % noOfElements[i];
				valueShifts[i] = (valueShifts[i] + K ) % noOfElements[i];
				K = K * 2;
			}
		}
		else{
			in(X);
			level = atLevel(X);
			//valueShifts[level] = (valueShifts[level] + noOfElements[level]) % noOfElements[level];
			valueShifts[level] = (valueShifts[level] + noOfElements[level]) % noOfElements[level];
			ll whoShouldIbe = X + valueShifts[level];
			if (whoShouldIbe >= 2 * noOfElements[level]){
				whoShouldIbe -= noOfElements[level];
			}
			while(level > 0){
				cout<<X<<" ";
				
				whoShouldIbe = whoShouldIbe / 2;
				level--;
				if(!level){
					cout<<"\n";
					break;
				}
                //valueShifts[level] = (valueShifts[level] + noOfElements[level]) % noOfElements[level];
				X = (whoShouldIbe - valueShifts[level]);
				if(X < noOfElements[level]){
					X += noOfElements[level];
				}
			}
		}
	}
	return 0;
}