/*input
5
1 2 2 2 1
3
1 3
1 4
1 5
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    
    int n;
    scanf("%d",&n);
    ll a[n];
    for(int i = 0;i<n;i++){
        scanf("%lld",a[i]);
        
    }
    
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        unordered_map<ll,ll> mp;
        for(int i = l;i<r;i++) mp[a[i]]++;
        int ans = 0;
        for(auto itr : mp){
            if(itr.second % 2 != 1){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}