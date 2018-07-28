/*input

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;


#define in(x) scanf("%lld",&x);

int main(){
	
	int n,m,k;
	cin>>n>>m>>k;

	string s[n];
	int count_one[n];
	for(int i = 0;i<n;i++){
		cin>>s[i];
		count_one[i] = 0;
		for(int j = 0;j<m;j++){
			if(s[i]=='1'){
				count_one[i]++;
			}
		}
	}

	unordered_map<int,int> vec[n];

	for(int i = 0;i<n;i++){

		for(int j = 0;j<m;j++){
			int cOne = 0;
			int time = 1;
			if(s[j]=='1'){
				cOne++;
			}

			if(count_one[i]-cOne<=k){
				vec[i].insert(make_pair(count_one[i]-cOne,time));
			}


			for(int k = j+1;k<m;k++){
				time++;
				if(s[k]=='1'){
					cOne++;
					if(count_one[i]-cOne<=k){
						if(vec[i].find(count_one[i]-cOne)==vec[i].end())
							vec[i].insert(make_pair(count_one[i]-cOne,time));
						else
							vec[i][count_one[i]-cOne] = min(vec[i][count_one[i]-cOne],time);
					}
				}
			}
		}
		
	}


	//sort(vec.begin(),vec.end());



	return 0;
}