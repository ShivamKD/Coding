/*input
4
82 94 6
56 67 4
28 59 9
39 74 4
*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int MAX_N = 1e6 + 1;

int G[MAX_N];
int pre[10][MAX_N];

void calculate()
{
	int n,f;
	for(int i = 1;i<MAX_N;i++)
	{
		n = i;
		while(n>9)
		{
			
			f = 1;
			while(n)
			{
				if(n%10!=0)
					f = f * (n%10);
				n /= 10;
			}
			n = f;
		}
		G[i] = n;
	}
}

void preCal()
{
	for(int i = 1;i<MAX_N;i++)
	{
		for(int j = 0 ;j<10;j++)
		{
			pre[j][i] = pre[j][i-1];
			if(G[i]==j)
				pre[j][i]++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    calculate();
    preCal();

    int l,r,k;
    int q;

    cin>>q;
    
    while(q--)
    {
    	cin>>l>>r>>k;
    	cout<<pre[k][r]-pre[k][l-1]<<endl;
    }
	
	return 0;
}