/*input
4
red
purple
yellow
orange
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll MOD = 1e9 + 7;

int main(){
	FIO
	string s[] = {"Power","Time","Space","Soul","Reality","Mind"};
	int a[6] = {0};
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		string b;
		cin>>b;
		if(b.compare("purple")==0){
			a[0] = 1;
		}
		if(b.compare("green")==0){
			a[1] = 1;
		}

		if(b.compare("blue")==0){
			a[2] = 1;
		}
		if(b.compare("orange")==0){
			a[3] = 1;
		}
		if(b.compare("red")==0){
			a[4] = 1;
		}

		if(b.compare("yellow")==0){
			a[5] = 1;
		}
	}
	cout<<6-n<<"\n";

	for(int i = 0;i<6;i++){
		if(a[i]==0){
			cout<<s[i]<<"\n";
		}
	}
	return 0;
}