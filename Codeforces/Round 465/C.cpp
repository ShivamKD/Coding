/*input
1 0 0 0 0
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
    ll R,a,b,c,d;
    cin>>R>>a>>b>>c>>d;
    double distance = sqrt((a-c)*(a-c) + (b-d)*(b-d));

    if(distance>=R)
    {
    	cout<<a*1.000<<" "<<b*1.000<<" "<<R*1.00;
    }
    else if(distance!=0.0)
    {
    	double radius = (distance + R) / 2;
    	double m = distance,n=R*1.00000000000;

    	double x = a * (m+n) - n * c;
    	x = x/m;

    	double y = (m+n) * b - n * d;
    	y = y/m;

    	printf("%.18lf %.18lf %.18lf",(x+c)/2.0,(y+d)/2.0,radius);
    	//cout<<(x+c)/2<<" "<<(y+d)/2<<" "<<radius;

    }
    else
    {
    	//cout<<"Here";
    	double radius = R/2.0;
    	double x = (a + radius);
    	cout<<x<<" "<<b<<" "<<" "<<radius;
    }

	return 0;
}