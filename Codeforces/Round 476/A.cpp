/*input
5 3 100 1
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 7;

int main(){
	FIO 
	int n,k,s,p;
	cin>>k>>n>>s>>p;

	int one = n  / s + (n%s!=0);
	int req = k * one;
	int answer = req / p + (req%p!=0);
	cout<<answer;

	return 0;
}