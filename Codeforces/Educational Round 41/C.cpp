/*input
1
0

0

1

0
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x)
#define loop(start,end) for(ll var = start; var < end; var++)
#define arr(a,n) loop(0,n) in(a[var])
#define parr(a,n) loop(0,n) printf("%lld ", a[var]);
const ll MOD = 1e9 + 7;

int answer = INT_MAX;

void check(string a[],string b[],string c[],string d[]){
	int count = 0;
	char first = '1';
	
	int n = a[0].length();
	string z[2*n];

	int counter2, counter;
	counter2 = counter = 0;

	for(int i = 0;i<n;i++){
		z[i] = a[i] + b[i];
	}
	for(int i = 0;i<n;i++){
		z[i+n] = c[i] + d[i];
	}


	for(int i = 0;i<2*n;i++){

		for(int j = 0;j<2*n;j++){

			if(z[i][j]!=first){
				counter++;
			}

			if(first=='1')
				first = '0';
			else
				first = '1';
		}
		if(first=='1')
			first = '0';
		else
			first = '1';
	}


	first = '0';

	for(int i = 0;i<2*n;i++){
		//cout<<z[i]<<"\n";
		for(int j = 0;j<2*n;j++){

			if(z[i][j]!=first){
				counter2++;
			}
			if(first=='1')
				first = '0';
			else
				first = '1';
		}
		if(first=='1')
			first = '0';
		else
			first = '1';
	}
	//cout<<counter<<endl;
	//cout<<endl;

	counter = min(counter,counter2);
	answer = min(answer,counter);
}

int main(){
	int n;
	cin>>n;
	string a[n],b[n],c[n],d[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}

	for(int i = 0;i<n;i++){
		cin>>b[i];
	}

	for(int i = 0;i<n;i++){
		cin>>c[i];
	}

	for(int i = 0;i<n;i++){
		cin>>d[i];
	}

	check(a,b,c,d);
	check(a,b,d,c);
	check(a,c,b,d);
	check(a,c,d,b);
	check(a,d,b,c);
	check(a,d,c,b);
	

	cout<<answer;
	return 0;
}