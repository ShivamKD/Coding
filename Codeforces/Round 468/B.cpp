/*input
4 1 2
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
int ans;

void check(ll a,ll b,int low,int high,int round){
    ans = round;
    int mid = (low+high)/2;

    if(low<=a && b<=mid){
        check(a,b,low,mid+1,round+1);
    }

    if(mid+1<=a && b<=high){
        check(a,b,mid+1,high,round+1);
    }
}


int main(){
    ll n,a,b;
    in(n);
    in(a);
    in(b);
    if(a>b)
        swap(a,b);
    ans = 0;

    check(a,b,1,n,0);

    ll m = n;
    int count = 0;
    while(n){
        n=n/2;
        count++;
    }

    ans = count - ans;
    if(ans==m){
        cout<<"Final!";
    }
    else
        cout<<ans;

	return 0;
}