#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
	ll n,d;
	cin>>n>>d;
	
	ll a;
	ll prev=0;
	ll sum=0;
	ll count=0;
	int flag=0;
	
	for(int i=0;i<n;i++)
	{
		cin>>a;
		sum+=a;
		if(sum>d)
		{
			flag=1;
			break;
		}
		
		if(a==0)
		{
			if(sum+prev<0)
			count++;
			
			prev=d;
			sum=0;
		}
	}
	if(flag)
	cout<<"-1";
	else
	cout<<count;
	
	return 0;	
}
