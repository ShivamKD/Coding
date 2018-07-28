/*input
3
1
1 4 1
2 5 3
*/
// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const ll MOD =  1e9 + 7;


int main(){
	FAST_IO

	ll n,m;
	cin>>n;
	cin>>m;
	ll a[n],b[n];

	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(a[i]==1){
			cout<<-1;
			return 0;
		}
	}

	for(int i = 0;i<n;i++){
		cin>>b[i];
		if(b[i]==1){
			cout<<-1;
			return 0;
		}
	}
	double M = m * 1.000000;
	double ans = 0.0;
	double toLand,toTakeOff,weight,fuel;
	fuel = M * 1.00000000/ (b[0] - 1);
	ans += fuel; 
	M = M + fuel;
	//cout<<fuel<<"\n";;
	for(int i = n-1;i>=0;i--){
		//cout<<M<<" ";
		fuel = M * 1.00000000 / (a[i] - 1);
		//cout<<fuel<<"\n";
		ans += fuel;
		if(i!=0){
			M += fuel;
			//cout<<M<<"\n";
			fuel = M * 1.000000000 / (b[i]-1);
			ans += fuel;
			M+= fuel;
		}
	}


	printf("%.9lf",ans);
	return 0;
}