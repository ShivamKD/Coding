/*input
333
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define in(x) scanf("%lld",&x)
const ll MOD = 1e9 + 7;

int n;
string s;
ll answer = -1;


void check(string curr,ll moves){

	if(curr[0]=='0'){
		return ;
	}
	ll x = 0;
	

	for(int i = 0;i<curr.length();i++){
		x = x * 10 + (curr[i]-'0');
	}
	//cout<<"--> "<<x<<"\n";
	ll p = (ll)(sqrt(x));

	if((p*p)==x){
		if(answer==-1){
			//cout<<"answer->"<<x<<"\n";
			answer = moves;
		}
		else{
			answer = min(answer,moves);
		}
	}
}
void recur(string curr,ll current,ll moves){

	if(current == n){
		//cout<<curr<<" ";
		if(curr.length()!=0)
		check(curr,moves);
		
		return ;
	}

	recur(curr+""+s[current],current+1,moves);

	recur(curr,current+1,moves+1);
}

int main(){
	
	cin>>s;
	n = s.length();

	recur("",0,0);

	cout<<answer;
	return 0;
}