/*input
5
0 0
1 0
2 1
1 1
2 3
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

int n;
int flag;
int a[100010][2];

pair<int,int> slope(int x1,int y1,int x2,int y2){
	int up = y2 - y1;
	int down = x2 - x1;
	int g = __gcd(up,down);
	up /= g;
	down /= g;

	if(down==0){
		up = 0;
	}
	return make_pair(up,down);
}

void check(int x,int y){
	if(flag){
		return ;
	}
	pair<int,int> currentSlope = slope(a[x][0], a[x][1], a[y][0], a[y][1]), otherSlope;

	vector <int> others;

	for(int i =1;i<=n;i++){
		if(i!=x && i!=y){
			otherSlope = slope(a[x][0], a[x][1], a[i][0], a[i][1]);
			if(currentSlope.first==otherSlope.first && currentSlope.second == otherSlope.second){
				;
			}
			else{
				others.push_back(i);
			}
		}
	}

	if(others.size()<3){
		flag = 1;
		return ;
	}



	currentSlope = slope(a[others[0]][0], a[others[0]][1], a[others[1]][0], a[others[1]][1]);

	for(int i = 2; i < others.size() ; ++i){
		otherSlope = slope(a[others[0]][0], a[others[0]][1], a[others[i]][0], a[others[i]][1]);

		if(currentSlope.first==otherSlope.first && currentSlope.second == otherSlope.second){
			;
		}
		else{
			return ;
		}

	}

	flag = 1;
}

int main(){

	cin>>n;
	
	if(n<=4){
		cout<<"YES";
		return 0;
	}

	for(int i = 1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}

	flag = 0;

	check(1,2);
	check(2,3);
	check(1,3);

	if(flag){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}

	return 0;
}