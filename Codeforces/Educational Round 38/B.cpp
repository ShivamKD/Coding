/*input
3
2 3 9
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int me = 1;
    int dost = (int)(1e6);
    const int f = dost;
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
    	cin>>a[i];
    
    
    int mid = dost/2;

    int i;
    for(i = 0;i<n;i++)
    {
    	if(a[i]>mid)
    	{
    		break;
    	}
    }

    if(i==n)
    	cout<<a[n-1]-1;
    else if(i==0)
    {
    	cout<<(f-a[0]);
    }
    else
    {
    	cout<<max(a[i-1]-1,f-a[i]);
    }

	return 0;
}