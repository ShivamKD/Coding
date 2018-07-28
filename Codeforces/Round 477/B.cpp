/*input
5 10 10
1000 1 1 1 1
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
const ll MOD = 1e9 + 7;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int arr[n-1];
	int f ;
	cin>>f;
	int sum = f;

	for(int i  = 0;i<n-1;i++) cin>>arr[i],sum += arr[i];

	double S = f * 1.0 * a / b;
	
	sort(arr,arr+ n - 1);
	
	int count = 0;

	for(int i = n-2;i>=0;i--){
	
		if(sum<=S){
			cout<<count;
			return 0;
		}
	
		count++;
		sum -= arr[i];
	
	}

	cout<<count;

	return 0;
}