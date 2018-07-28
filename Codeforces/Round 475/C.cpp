/*input
4 1 5 1
-
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%lld",&x);
const ll MOD = 1e9 + 9;

int power(ll x, unsigned ll y, ll p)
{
    ll res = 1;     
    x = x % p;  
 
    while (y > 0)
    {
       
        if (y & 1)
            res = (res*x) % p;
 
     
        y = y>>1; 
        x = (x*x) % p;  
    }
    return res;
}

ll modInverse(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
 
        m = a % m, a = t;
        t = y;
 
        y = x - q * y;
        x = t;
    }
 
 
    if (x < 0)
       x += m0;
 
    return x;
}

ll gp(ll terms, ll a,ll first_term){
	//cout<<"In ";

	if(a==1){
		ll ans = first_term * (terms +1) ;
		ans %= MOD;
		return ans;
	}

	ll ans = (first_term * (power(a,terms + 1,MOD) - 1 + MOD) % MOD) % MOD ;
	//cout<<power(a,terms + 1,MOD)<<endl;

	ans = ans * modInverse(a-1,MOD);
	return ans;
}

int main(){
	FIO 
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	string s ;
	cin>>s;

	ll answer = 0;

	//cout<<gp(0,2,10)<<endl;

	if(n<k){
		ll fb = 1;
		for(int i = 0;i<=n;i++){
			ll f = fb * power(a,n-i,MOD);
			//cout<<f<<" ";
			f = f % MOD;
			fb = fb * b % MOD;

			if(s[i]=='+'){
				//cout<<"add\n";
				answer += f ;
			}
			else{
				//cout<<"sub\n";
				answer += -f +MOD;
			}
			answer %= MOD;
		}

		cout<<answer<<endl;
		return 0;
	}


	ll b_a = b * modInverse(a,MOD);

	b_a = power(b_a,k,MOD);

	ll fa = 1, fb = 1;

	for(int i = 0;i<k;i++){

		ll terms = (n - i + 1) / k + ((n-i+1)%k!=0);
		
		ll first_term = power(a,n-i,MOD);
		first_term *= fb;
		first_term %= MOD;
		
		terms--;

		ll f = gp(terms,b_a,first_term);
		f =  f % MOD;
		//cout<<first_term<<endl;
		
		fa = fa * a;
		fa %= MOD;
		fb =fb * b;
		fb %= MOD;

		if(s[i]=='+')
		answer += f;
		else
		answer -= f;

		answer %= MOD;
	}
	answer += MOD;
	answer %= MOD;

	cout<<answer;
	return 0;
}