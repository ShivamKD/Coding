/*
 *  @ShivamKD
 *
 *  Shivam Kumar Dubey
 *
 */

#include <bits/stdc++.h>
#define ll long long

using namespace std;


const ll MOD = (1e9) + 7;
const int M = 1000;
int special[M+1];

ll comb(int N,int R)
{
	;
	ll ans = 1;
	R = max(R,N-R);
	for(int i = R+1;i<=N;i++)
	{
		ans = ans * i;
		ans = ans  % MOD;
	}
	
	return ans;
}

void cal()
{
	special[1] = 0;
	for(int i = 2;i<=M; i++)
	{
		int n = i;
		int count = 0;
		while(n)
		{
			count++;
			n=n&(n-1);
		}
		special[i] = 1 + special[count];
	}
}

ll val(int setBit,int N, string s)
{
	ll ans = 0;
	//cout<<setBit<<" "<<N<<"\n";
	for(int i=setBit;i<N;i++)
	{
		ans += comb(i-1,setBit-1);
		ans %= MOD;
	}
	
	//cout<<ans<<endl;
	int one = 1;
	int R = setBit;
	
	for(int i=1;i<s.length();i++)
	{
		if(s[i]=='1')
		{
			R = setBit - one;
			if(R <=(s.length()-i-1))
			{
				ans += comb(s.length()-i-1,R);
				ans %= MOD;
				//cout<<ans<<endl;
			}
			one++;
		}
		else if(one == setBit)
		{
			ans += 1;
			ans %= MOD;
			break;
		}
	}
	
	return ans;
}


int main()
{
	int i;
	cal();
	
	string s;
	int k;
	cin>>s;
	cin>>k;
	
	int n = s.length();
	
	
	ll ans = 0;
	
	for(int i =1;i<=n;i++)
	{
		if(special[i]==(k-1))
		{
			//cout<<i<<" ";
			//if(i==8)
			cout<<"8-->"<<val(i,n,s)<<" ";
			ans = ans + val(i,n,s);
			ans %= MOD;
		}
	}
	
	cout<<ans;
	return 0;
}



