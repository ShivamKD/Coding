/*input
10 3 7
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int x = -1,y = -1;
	for(int i = 0;i<=n/a;i++){
		int rem = n - a * i;

		if(rem%b==0){
			y = rem/b;
			x = i;
			break;
		}
	}

	if(x==-1 && y==-1){
		cout<<"-1";
		return 0;
	}


	int current = a;

	for(int i = 1;i<=x;i++){
		cout<<current<<" ";
		current++;
		for(int j = 1;j<a;j++){
			cout<<(current-a)<<" ";
			current++;
		}
	}

	current -= a;
	current += b;

	for(int i = 1; i<=y;i++){
		cout<<current<<" ";
		current++;
		for(int j = 1;j<b;j++){
			cout<<(current-b)<<" ";
			current++;
		}

	}
	return 0;
}