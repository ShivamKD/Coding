/*input
4
word
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
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
    	cout<<s[i];
    	if(s[i]=='a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i]=='i' || s[i]=='y')
    	{
    		i+=1;
    		while(i<n)
    		{
    			
    			if(s[i]=='a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i]=='i' || s[i]=='y')
    			{
    				;
    			}
    			else
    			{
    				cout<<s[i];
    				break;
    			}
    			i+=1;
    		}
    	}
    	
    }
	return 0;
}