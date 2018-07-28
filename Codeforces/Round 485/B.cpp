/*input
6 6
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1e9 + 7;

int main(){
	FIO
	ll a,b;
	cin>>a>>b;
	if(a==1 or b==1){
		if(a==1 and b==1){
			cout<<"=";
		}
		else if(a>b){
			cout<<">";
		}
		else{
			cout<<"<";
		}
		return 0;
	}

	
	double first = b * log10(a);
	//cout<<first<<"\n";
	double second = a * log10(b);
	//cout<<first<<" "<<second<<"\n";
	if(first>second)
		cout<<">";
	else if(first<second)
		cout<<"<";
	else
		cout<<"=";

	return 0;
}