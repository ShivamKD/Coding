/*input
100111222
*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;
int main(){
	FAST_IO

	string s;
	cin>>s;
	int a[s.length()];
	int n = s.length();
	int ans = 0;
	for(int i = 0;i<n;i++){
		int x = s[i]-'0';
		a[i] = x % 3;
		if(a[i]==0){
			ans++;
		}
	}

	for(int i = 0;i<n;i++){
		if(a[i]==1){
			if(i<n-1){
				if(a[i+1]==2){
					ans++;
					a[i] = 0;
					a[i + 1] = 0;
					continue;
				}
			}
			if(i < n -2){
				if(a[i+1]==1 and a[i+2]==1){
					ans++;
					a[i] = 0;
					a[i+1] = 0;
					a[i+2] = 0;
					continue;
				}
			}
		}

		if(a[i] == 2){
			if(i<n-1){
				if(a[i+1]==1){
					ans++;
					a[i] = 0;
					a[i+1] = 0;
					continue;
				}
			}

			if(i<n-2){
				if(a[i+1]==2 and a[i+2]==2){
					ans++;
					a[i] = a[i+1] = a[i + 2] = 0;
					continue;
				}
			}
		}
	}

	cout<<ans;
	return 0;
}