/*input
5 3 1 1 3
2 2 2 1 1
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
	int n,a,b,c,t;
	cin>>n>>a>>b>>c>>t;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	int wait = a / b;
	long answer = 0;

	if(c>=b){
		for(int i = 0;i<n;i++){
			answer += (t-arr[i]) * c + a - (t-arr[i])*b;
		}

	}
	else{
		for(int i = 0;i<n;i++){
			answer += a;
		}
	}

	cout<<answer<<endl;

	return 0;
}