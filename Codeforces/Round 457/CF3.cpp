/**
  * Author : ShivamKD
  * Status Accepted : Done
  * Question : http://codeforces.com/contest/916/problem/C
  */

/*input
10 11
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll F = 104729;

int main()
{
	int n,m;
	cin>>n>>m;
	if(m==1)
	{
		cout<<2<<" "<<2<<"\n";
		cout<<1<<" "<<2<<" "<<2<<"\n";
		return 0;
	}

	cout<<2<<" "<<F<<"\n";
	cout<<1<<" "<<(n)<<" "<<2<<"\n";
	ll total = 2;
	for(int i = 2; i <= n-2; i++)
	{
		cout<<1<<" "<<i<<" "<<1<<"\n";
		total += 1;
	}
	total = F - total;
	cout<<1<<" "<<(n-1)<<" "<<total<<"\n";

	m = m - (n-1);

	for(int i=2;i<=n && m!=0;i++)
	{
		for(int j = i+1;j<=n & m!=0;j++)
		{
			cout<<i<<" "<<j<<" "<<(F+1)<<"\n";
			m--;
		}
	}
	return 0;
}