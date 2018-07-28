/*input
1 2
1
0
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = (1e9) + 7;
const ll MAX = (1e6) + 1;


// Attribution: GeeksforGeeks
ll power(ll x,  ll y)
{
	ll p = MOD;
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

// Attribution: GeeksforGeeks
ll modInverse(ll a)
{
	ll m = MOD;
    ll m0 = m;
    ll y = 0, x = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        // q is quotient
        ll q = a / m;
        ll t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
       x += m0;
 
    return x;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    ll a[n],b[n];
    ll zero = 0, both_zero = 0;
    for(int i = 0;i<n;i++)
    {
    	cin>>a[i];
    	if(a[i]==0)
    		zero++;

    }

    for(int i = 0;i<n;i++)
    {
    	cin>>b[i];
    	if(b[i]==0)
    		zero++;
    	if(a[i]==0 && b[i]==0)
    		both_zero++;
    }

    ll q = power(m,zero);
    //cout<<q<<endl;
    ll p = 0;
    ll dup = zero;
    ll temp[n];
    int flag = 0;
    ll curr = 0,curr1 = 0,all;
    for(int i=0;i<n;i++)
    {
    	curr = 0;


    	if(a[i]==0 && b[i]==0)
    	{
    		curr = m * (m+1)/2 ;
    		zero -= 2;
    	}
    	else if(a[i]==0)
    	{
    		curr = (m-b[i]) + 1;
    		zero --;
    	}
    	else if(b[i]==0)
    	{
    		curr = a[i] ;
    		zero--;
    	}
    	else if(a[i]>b[i])
    	{
    		flag = 1;
    		break;
    	}	
    	
    	
    	if(p==0)
    		p = curr %MOD;
    	else 
    		p = (p%MOD * curr%MOD)%MOD;
    }

    if(flag)
    {
    	if(p==0 && zero!=0)
    		p=1;

    	p = (p % MOD * power(m,zero)%MOD) % MOD;
    }
    else
    {
    	//cout<<zero;
    	p = p - both_zero * m - (dup - both_zero * 2);
    	p = (p + MOD) % MOD;
    }
    /*
    else
    {
    	all = 0;
    	for(int i = 0;i<n;i++)
    	{
    		if(a[i]==0 && b[i]==0)
	    	{
	    		curr = m * (m+1)/2 ;
	    		zero -= 2;
	    	}
	    	else if(a[i]==0)
	    	{
	    		curr = (m-b[i]) + 1;
	    		zero--;
	    	}
	    	else if(b[i]==0)
	    	{
	    		curr = a[i] ;
	    		zero--;
	    	}
	    	all += curr;

	    	if(a[i]==0 && b[i]==0)
	    	{
	    		curr1 = m * (m-1)/2 ;
	    		zero -= 2;
	    	}
	    	else if(a[i]==0)
	    	{
	    		curr1 = (m-b[i]) ;
	    		zero--;
	    	}
	    	else if(b[i]==0)
	    	{
	    		curr1 = a[i] - 1 ;
	    		zero--;
	    	}
	    	all += curr1;
    	}
    }

    all = all - curr;
    p = (p * modInverse(curr)) % MOD;
    p = p * curr1 + all;
    p = p % MOD;
	*/
	//cout<<p<<" "<<q<<endl;
    ll g = __gcd(p,q);
    p = p/g;
    q = q/g;


    ll ans = (p %MOD)* modInverse(q) % MOD;
    ans = ans % MOD;
    cout<<ans;
	return 0;
}