/*input
2 5 7
3 4
14 4
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 7;

int main(){

	ll n,k1,k2;
	in(n);
	in(k1);
	in(k2);
	ll a[n],b[n],c[n];

	for(int i = 0;i<n;i++) in(a[i]);

	for(int i = 0;i<n;i++) in(b[i]);

	for(int i = 0;i<n;i++){
		c[i] = abs(a[i]-b[i]);
	}

	sort(c,c+n);
	ll x = k1 + k2;
	//cout<<c[0]<<" ";

	while(x!=0){
		int flag = 1;

		for(int i = n-1;i>=0 && (x!=0);i--){

			if(c[i]){
				if(i>0){
				 	if(c[i]>=c[i-1]){
						c[i]--;
						x--;
						i = n;
						flag = 1;
					}
				}
				else{
					
					c[i]--;
					x--;
					i = n;
					flag = 1;
				}
		}
			
		}
		if(flag)
			break;
	}
	//cout<<x<<" ";
	c[0] += x%2;
	/*
	while(k1!=0){
		int flag = 1;

		for(int j = 0;j<n && k1!=0;j++){

			if(a[j]>b[j]){
				a[j]--;
				k1--;
				flag = 0;
			}
			else if(a[j]<b[j]){
				a[j]++;
				k1--;
				flag = 0;
			}
			
		}
		if(flag){
			break;
		}

	}

	if(k1!=0){
		a[0] += k1%2;
	}

	while(k2!=0){
		int flag = 1;
		for(int j = 0;j<n && k2!=0;j++){
			if(a[j]>b[j]){
				b[j]++;
				k2--;
				flag = 0;
			}
			else if(a[j]<b[j]){
				b[j]--;
				k2--;
				flag = 0;
			}
			
		}
		if(flag){
			break;
		}
	}

	if(k2!=0){
		b[0] += k2%2;
	}*/
	ll answer = 0;
	
	for(int i = 0;i<n;i++){
		answer += c[i] * c[i];
	}

	printf("%lld\n", answer);
	return 0;
}