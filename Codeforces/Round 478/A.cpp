/*input
3
amer arem mrea
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n;
	cin>>n;
	string s;
	set<set<char> > ch;
	
	for(int i = 0;i<n;i++){
		cin>>s;
		set<char> p;
		for(int j = 0;j<s.length();j++){
			p.insert(s[j]);
		}
		ch.insert(p);
	}
	cout<<ch.size();

	return 0;
}