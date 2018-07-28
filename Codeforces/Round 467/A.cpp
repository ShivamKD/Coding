/*input
4
42 0 0 42
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = (1e9) + 7;
const ll MAX = (1e6) + 1;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++)
    {
    	int x;
    	cin>>x;
    	if(x!=0)
    		s.insert(x);
    }
    cout<<s.size();
	return 0;
}