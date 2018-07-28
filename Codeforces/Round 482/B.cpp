/*input
1
abcabc
cbabac
ababca
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll n;
	cin>>n;
	string a,b,c;
	cin>>a;
	cin>>b;
	cin>>c;
	if(n>=a.length()){
		cout<<"Draw";
		return 0;
	}

	unordered_map<char,int> a1,b1,c1;

	int ans[3];
	ans[0] = ans[1] = ans[2] = 0;
	for(int i = 0;i<a.length();i++){
		a1[a[i]]++;

		ans[0] = max(ans[0],(int)a1[a[i]]);
		b1[b[i]]++;
		ans[1] = max(ans[1],(int)b1[b[i]]);
		c1[c[i]]++;

		ans[2] = max(ans[2],(int)c1[c[i]]);
	}
	int mn = min(ans[0],min(ans[1],ans[2]));
	if(mn + n >=a.length()){
		cout<<"Draw";
		return 0;
	}

	if(n==1){
		if(ans[0] == a.length())
			ans[0]--;
		else
			ans[0]++;

		if(ans[1]==a.length())
			ans[1]--;
		else
			ans[1]++;

		if(ans[2] == a.length())
			ans[2]--;
		else
			ans[2]++;

	}

	if(ans[0] > ans[1] and ans[0] > ans[2]){
		cout<<"Kuro";
	}
	else if(ans[1] > ans[2] and ans[1] > ans[0]){
		cout<<"Shiro";
	}
	else if(ans[2] > ans[0]  and ans[2] > ans[1]){
		cout<<"Katie";
	}
	else{
		cout<<"Draw";
	}
	
	return 0;
}