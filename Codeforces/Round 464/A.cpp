/*input
5
2 4 5 1 3
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
    int a[n];
    int b[n+1] = {0};
    for(int i=0;i<n;i++)
    cin>>a[i];

    for(int i=0;i<n;i++)
    {
       int A = a[i];
       int B = a[A-1];
       int C = a[B-1];
       if(C==i+1)
       {
       	cout<<"YES";
       	return 0;
       }
    }
    cout<<"NO";

	return 0;
}