/*input
3
1 1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x);

const ll MOD = 1e9 + 7;

/*
fast INPUT
void in(int &x){
    char c = getchar_unlocked();
    while(c<'0' || c>'9')
    {
        c = getchar_unlocked();
    
    }
    x=0;
    while(c>='0' && c<='9')
    {
        x = 10 * x + c - 48;
        c = getchar_unlocked();
    }
}
*/

vector<ll> vec[100010];
int c[100010];
bool visited[100010];

void dfs(int current,int level){
    visited[current] = true;
    c[level]++;

    //for( int x : vec[current]){
    for(int i = 0;i<vec[current].size();i++){
        int x = vec[current][i]; 
        if(!visited[x]){
            dfs(x,level+1);
        }
    }
}

int main(){
    ll n;
    in(n);
    //unordered_map<ll,ll> un;

    ll temp;
    for(int i = 2;i<=n;i++){
        in(temp);
        vec[temp].push_back(i);
        vec[i].push_back(temp);
    }

    memset(visited, false, sizeof(visited));

    dfs(1,1);

    int answer = 0;

    for (int i = 1; i <= n; ++i)
    {
        /* code */
        answer = answer + c[i]%2;
    }

    printf("%d\n", answer);
	return 0;
}