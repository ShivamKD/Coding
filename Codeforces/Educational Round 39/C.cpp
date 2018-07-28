/*input
thereisnoanswer
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;


#define in(x) scanf("%lld",&x);


int main(){
	string s;
	cin>>s;
	char c = 'a';
	string ans = "";
	int flag = 0;
	for(int i = 0;i<s.length();i++){
		
		if(s[i]<=c){
			ans += c;
			c++;
		}
		else{
			ans += s[i];
		}


		if(c>'z'){
			ans += s.substr(i+1);
			flag = 1;
			break;

		}
	}
	if(flag)
		cout<<ans;
	else{
		cout<<-1;
	}

	return 0;
}