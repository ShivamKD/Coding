/*input
21
18 0 18 2 21 2 9 15 3 5 8 2 8 21 6 10 21 13 9 1 13	
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 7;
const int sz = 2e5 + 10;
set<int> s[sz];
set<int> all;
vector<int> solution;
int flag = 0;

void doIt(int p,int parent){
	//cout<<p<<"\n";
	if(flag)
		return ;
	
	int f = 1;

	while(f and !flag){
		f = 0;

		for(int x : s[p]){
			if(x!=parent and all.find(x)!=all.end()){
			//if(s[x].size()%2==0 and s[x].size()!=0){

				doIt(x,p);
				//f = 1;
				
			}
		}


	}

	if(s[p].size()%2==0 and s[p].size()!=0 and !flag){
		solution.push_back(p);
		all.erase(p);
		//cout<<p<<" "<<s[p].size()<<"\n";
		while(s[p].size()!=0){
			auto itr = s[p].begin();
			int n = *itr;
			s[p].erase(itr);
			s[n].erase(p);
			//cout<<p<<"-->"<<n<<"\n";
			//if(n!=parent)
			doIt(n,p);
		}

	}
	

}

int main(){
	FIO 

	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		all.insert(i);
	}	

	for(int i = 1;i<=n;i++){
		int p;
		cin>>p;
		if(p!=0){
			s[p].insert(i);
			s[i].insert(p);	
			//cout<<p<<" "<<i<<"\n";
		}
	}

	for(int i = 1;i<=n and !flag;i++){
		doIt(i,0);
	}

	for(int i = 1;i<=n;i++){
		if(s[i].size()){
			flag = 1;
			break;	
		}
	}

	if(flag){
		cout<<"NO\n";
		return 0;
	}

	cout<<"YES\n";
	for(int x : solution)
		cout<<x<<"\n";
	for(int x : all)
		cout<<x<<"\n";
	return 0;
}