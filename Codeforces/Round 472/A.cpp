/*input
4
C?Y?
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x)
#define loop(start,end) for(ll var = start; var < end; var++)
#define arr(a,n) loop(0,n) in(a[var])
#define parr(a,n) loop(0,n) printf("%lld ", a[var]);
const ll MOD = 1e9 + 7;



int main(){
	int n;
	cin>>n;

	string s;
	cin>>s;
	int flag = 0, done = 0;

	for(int i = 0;i<n;i++){

		if(s[i]=='?'){
			done++;
		}

		if(s[i]==s[i-1] && s[i]!='?'){
			cout<<"No";
			return 0;
		}
		else if(s[i]=='?'){
			if(i>0 && i<n-1){
				if(s[i-1]!=s[i+1] && s[i-1]!='?' && s[i+1]!='?'){
					flag++;
				}
			}

		}

	}
	//cout<<flag<<" "<<done<<endl;
	if(flag == done){
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
}