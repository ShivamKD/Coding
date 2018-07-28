/*input
9 14
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	FIO
	int n,k;
	cin>>n>>k;
	int a[4][n];
	memset(a,0,sizeof(a));

	if(k%2==0){

		cout<<"YES\n";
		for(int i = 1;i<n-1 and k;i++){
			a[1][i] = 1;
			a[2][i] = 1;
			k = k - 2;
		}
		for(int i = 0;i<4;i++){
			for(int  j = 0;j<n;j++){
				if(a[i][j]){
					cout<<"#";
				}
				else{
					cout<<".";
				}
			}
			cout<<"\n";
		}
	}
	else{
		if(k>=n-2){
			cout<<"YES\n";
			for(int i = 0;i<n;i++){
				cout<<".";

			}
			cout<<"\n.";
			for(int i = 0;i<n-2;i++){
				cout<<"#";
			}
			cout<<".\n";
			k = k - (n  - 2);
			cout<<".";
			if(k>0){
				cout<<"#";
			}
			else{
				cout<<".";
			}
			k--;
			for(int i = 0;i<n-4;i++){
				if(k>1){
					cout<<"#";
					k--;
				}
				else{
					cout<<".";
				}
			}
			if(k == 1)
				cout<<"#.\n";
			else
				cout<<"..\n";
			for(int i = 0;i<n;i++){
				cout<<".";
			}
		}
		else{
			for(int i = n/2 - k/2;i<=n/2+k/2;i++){
				a[1][i] = 1;
			}
			cout<<"YES\n";

			for(int i = 0;i<4;i++){
			for(int  j = 0;j<n;j++){
				if(a[i][j]){
					cout<<"#";
				}
				else{
					cout<<".";
				}
			}
			cout<<"\n";
		}

		}
	}
	
	return 0;
}