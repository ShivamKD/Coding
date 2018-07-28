/*input
7
3 4 1 2 2 1 1
*/

// author : ShivamKD

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define in(x) scanf("%lld",&x)
const ll MOD = 1e9 + 7;

bool myComp(pair<ll,ll> a, pair<ll, ll> b){
	if(a.first == b.first){
		return a.second < b.second;
	}
	return a.first < b.first;
}

bool myComp2(pair<ll,ll> a, pair<ll, ll> b){
	
		return a.second < b.second;
	
}

int main(){
	
	ll n;in(n);
	ll x;
	set<ll> s;
	unordered_map<ll, vector< ll > > un;
	
	for(int i = 0;i<n;i++){
	    in(x);
	    
	    if(un.find(x)==un.end()){
	        un.insert(make_pair(x,vector< ll > ()));
	    }
	    
	    un[x].push_back(i);
	    s.insert(x);
	}
	/*
	for(auto itr : un){
	    for(ll x : itr.second){
	        cout<<x<<" ";
	    }
	    cout<<endl;
	}*/
	
	vector<pair<ll, ll > > solution;
	
	while(s.size()!=0){
	    
	    //cout<<s.size()<<" ";
	    auto itr = s.begin();
	    ll num = (ll)(*itr);
	    //cout<<num<<" ";
	    s.erase(itr);
	    
	    ll count = (ll) un[num].size();
	    sort(un[num].begin(),un[num].end());
	    
	    
	    if(count>=2){
	        
	        
	        
	        num = num * 2;
	        
	        if(count%2){
	            solution.push_back({num/2,un[num/2][un[num/2].size()-1]});
	        }
	        
	        
	        if(un.find(num)==un.end()){
	            un.insert(make_pair(num,vector< ll > ()));
	            s.insert(num);
	        }
	        //cout<<un[num/2].size()<<"\n";
	        ll mb = 0;
	        for(ll x : un[num/2]){
	            if(mb%2)
	                un[num].push_back(x);
	           mb++;
	        }
	        
	    }
	    else{
	        solution.push_back({num,un[num][0]});
	    }
	}
	
	sort(solution.begin(),solution.end(),myComp2);
	
	cout<<solution.size()<<"\n";
	for(int i = 0;i<solution.size();i++){
	    cout<<solution[i].first<<" ";
	}
	
	return 0;
}