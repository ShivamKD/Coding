/*input
5 2
0 2 1 255 254
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;
int a[1000];
int val[100010];
int n,k;

int main(){
	FIO
	cin>>n>>k;
	for(int i = 0;i<n;i++){
		cin>>val[i];
	}	
	for(int i = 0;i<n;i++){
		if(a[val[i]]!=0){
			if(a[val[i]]==-1)
				cout<<"0 ";
			else
				cout<<a[val[i]]<<" ";
		}
		else{
			int start = max(0,val[i] - k + 1);
			if(a[start]==0){
				for(int j = start;j<=val[i];j++){
					a[j] = start;
					if(start==0)
						a[j] = -1;
				}
			}
			else{
				int l = val[i];
				while(a[l]==0){
					l--;
				}
				l = a[l];
				if(l==-1)
					l = 0;
				if(l+k>val[i]){
					for(int j = l;j<=val[i];j++){
						a[j] = l;
						if(l==0)
							a[j] = -1;
					}
				}
				else{
					while(a[l]){
						l++;
					}
					for(int j = l;j<=val[i];j++){
						a[j] = l;
						if(l==0)
							a[j] = -1;
					}
				}
			}
			if(a[val[i]]==-1)
				cout<<"0 ";
			else
				cout<<a[val[i]]<<" ";
		}
	}
	return 0;
}