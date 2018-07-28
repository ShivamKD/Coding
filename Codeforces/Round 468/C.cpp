/*input

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



int main(){

    ll n;
    in(n);

    ll temp;
    unordered_map<ll,int> un;

    for(int i = 0;i<n;i++){
        in(temp);
        if(un.find(temp)==un.end())
            un.insert({temp,1});
        else
            un[temp]++;
    }

    ll mx,mid,mn;


    if(un.size()==1){
        cout<<n<<"\n";
        ll a = un.begin()->first;

        for(int i = 0;i<n;i++){
            cout<<a<<" ";
        }
    }
    else if(un.size()==2){
        ll a = un.begin()->first;
        ll aFreq = un[a];
        auto itr = un.begin();
        itr++;
        ll b = itr->first;
        ll bFreq = un[b];

        if(abs(a-b)==1){
            cout<<n<<"\n";
            for (int i = 0; i < aFreq; ++i)
            {
                /* code */
                cout<<a<<" ";
            }
            for (int i = 0; i < bFreq; ++i)
            {
                cout<<b<<" ";
                /* code */
            }

        }
        else{
            ll m = min(aFreq,bFreq) * 2;
            cout<<n - m<<"\n";
            for (int i = 0; i < m; ++i)
            {
                /* code */
                cout<<min(a,b)+1<<" ";
            }

            aFreq -= m/2;
            bFreq -= m/2;
            for (int i = 0; i < aFreq; ++i)
            {
                cout<<a<<" ";
                /* code */
            }
            for (int i = 0; i < bFreq; ++i)
            {
                cout<<b<<" ";
                /* code */
            }
        }
    }
    else{
        ll a[3];
        auto itr = un.begin();
        a[0] = itr->first;
        itr++;
        a[1] = itr->first;
        itr++;
        a[2] = itr->first;

        sort(a,a+3);

        ll b[3] = {un[a[0]],un[a[1]],un[a[2]]};
        //out<<b[0]<<" "<<b[1]<<" "<<b[2]<<"\n";

        if(min(b[0],b[2])*2>=b[1]){
            cout<<n - min(b[0],b[2])*2<<"\n";
            ll m = min(b[0],b[2]);
            b[0] -= m;
            b[2] -= m;
            b[1] += m*2;
            for (int i = 0; i < b[0]; ++i)
            {
                cout<<a[0]<<" ";
                /* code */
            }
            for (int i = 0; i < b[1]; ++i)
            {
                cout<<a[1]<<" ";
                /* code */
            }
            for (int i = 0; i < b[2]; ++i)
            {
                cout<<a[2]<<" ";
                /* code */
            }
        }
        else{
            ll m = b[1] - b[1]%2;
            cout<<n-m<<"\n";
            for (int i = 0; i < b[0]; ++i)
            {
                cout<<a[0]<<" ";
                /* code */
            }
            for (int i = 0; i < b[2]; ++i)
            {
                cout<<a[2]<<" ";
                /* code */
            }
            for (int i = 0; i < m/2; ++i)
            {
                cout<<a[0]<<" "<<a[2]<<" ";
                /* code */
            }
            if(b[1]%2)
                cout<<a[1];
        }

    }



    return 0;
}