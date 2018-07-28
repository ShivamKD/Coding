/*input
3 2 3
***
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define in(x) scanf("%lld",&x)
const ll MOD = 1e9 + 7;


int main(){
	ll n,a,b;
	in(n);
	in(a);
	in(b);
	string s;
	cin>>s;
	int answer = 0;
	int last = 0;

	for(int i = 0;i<n;i++){

		if(s[i]=='.'){
			if(last==0){
				if(a>b){
					a--;
					answer++;
					last = 1;
				}
				else{
					if(b!=0){
						b--;
						answer++;
						last = 2;
					}
					else{
						last = 0;
					}
				}
			}
			else if(last == 1){
				if(b!=0){
					b--;
					answer++;
					last = 2;
				}
				else{
					last = 0;
				}
			}
			else{
				if(a!=0){
					a--;
					last = 1;
					answer++;
				}
				else{
					last = 0;
				}
			}
		}
		else{
			last = 0;
		}
		if(a==0 && b==0){
			break;
		}
	}
	printf("%d\n", answer);
	return 0;
}