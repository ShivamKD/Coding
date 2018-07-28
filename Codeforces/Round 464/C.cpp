/*input
4
9 10 9 9
2 3 
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a[n*2];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    	a[n+i]=a[i];
    }

    int s , f;
    cin>>s>>f;
    
    int size = f-s;
    int pre = 0;
    int ma = INT_MIN;
    int ans = INT_MAX;

    for(int i = 0;i<n+size;i++)
    {
    	if(i+1<size)
    		pre+=a[i];
    	else
    	{
    		pre+=a[i];
    		//cout<<pre<<" ";
    		if(pre>ma)
    		{
    			//cout<<i<<endl;
    			ans = (i + s) % n;
    			if(ans==0)
    				ans = n;
    			ma = pre;
    		}
    		else if(pre == ma)
    		{
    			int f = (i+s)%n;
    			if(f==0)
    				f = n;
    			ans = min(ans,f);
    		}
    		pre -= a[i-size+1];
    		//out<<pre<<endl;
    	}
    }
    cout<<ans;
	return 0;
}