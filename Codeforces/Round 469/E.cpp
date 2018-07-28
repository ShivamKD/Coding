/*input
0010100
*/
#include <set>          
#include <map>           
#include <list>
#include <ctime>
#include <deque>   
#include <queue>      
#include <bitset>        
#include <vector>
#include <list>
#include <stack>
#include <random>		 
#include <string>       
#include <numeric>      
#include <utility>     
#include <iterator> 
#include <fstream>
#include <iostream> 
#include <iomanip>  
#include <algorithm> 
#include <functional>  
#include <unordered_map>  
#include <unordered_set>
#include <cmath>   
#include <cstring>  
#include <cstdio>    
#if !defined Header_DR
	#define Header_DR
	#pragma warning(disable:4996)
	#define intt long long
	#define cin user_input
	#define cout output
	#define pi 3.14159265358979323846
	#define code_jam 0
	#define code_chef 0
	#define rep(i,a,b) for(long long i=a;i<b;i++)
	#define all(v) v.begin(),v.end() 
	#define ve vector
	#define pb push_back                    
	#define srt(x) sort(x.begin(),x.end())         
	#define mod static_cast<long long> (1e9+7)     
	#define sumx(x) accumulate(x.begin(),x.end(),0LL)
	#define endl "\n"
#endif
#ifdef _WIN32
	#define getcx _getchar_nolock
#endif
#ifdef unix
	#define getcx getchar_unlocked
#endif
#if!defined FAST_IO
	#undef cin
	#undef cout
	#define FAST_IO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	#define cin user_input
	#define cout output
#endif
using namespace std;
namespace Xrocks {}
using namespace Xrocks;
namespace Xrocks
{
	class in {}user_input;
	class out {}output;
	in& operator >> (in& X, int &Y)
	{
		scanf("%d", &Y);
		return X;
	}
	in& operator >> (in& X, char *Y)
	{
		scanf("%s", Y);
		return X;
	}
	in& operator >> (in& X, float &Y)
	{
		scanf("%f", &Y);
		return X;
	}
	in& operator >> (in& X, double &Y)
	{
		scanf("%lf", &Y);
		return X;
	}
	in& operator >> (in& X, char &C)
	{
		scanf("%c", &C);
		return X;
	}
	in& operator >> (in& X, string &Y)
	{
#undef cin
		cin >> Y;
#define cin user_input
		return X;
	}
	in& operator >> (in& X, long long &Y)
	{
		scanf("%lld", &Y);
		return X;
	}
	template<typename T>
	in& operator >> (in& X, vector<T> &Y)
	{
		for (auto &x:Y)
			cin >> x;
		return X;
	}
	template<typename T>
	out& operator >> (out& X, vector<T> &Y)
	{
		for (auto &x:Y)
			cout  << x;
		return X;
	}
	out& operator <<(out& X, const int &Y)
	{
		printf("%d", Y);
		return X;
	}
	out& operator <<(out& X, const char &C)
	{
		printf("%c", C);
		return X;
	}
	out& operator <<(out& X, string &Y)
	{
		printf("%s",Y.c_str());
		return X;
	}
	out& operator <<(out& X, const long long &Y)
	{
		printf("%lld", Y);
		return X;
	}
	out& operator <<(out& X, const float &Y)
	{
		printf("%f", Y);
		return X;
	}
	out& operator <<(out& X, const double &Y)
	{
		printf("%lf", Y);
		return X;
	}
	out& operator <<(out& X, const char Y[])
	{
		printf("%s", Y);
		return X;
	}
	template<typename T>
	T max(T A)
	{
		return A;
	}
	template<typename T, typename... args>
	T max(T A, T B, args... S)
	{
		return max(A > B ? A : B, S...);
	}
	template<typename T>
	T min(T A)
	{
		return A;
	}
	template<typename T, typename... args>
	T min(T A, T B, args... S)
	{
		return min(A < B ? A : B, S...);
	}
	long long fast(long long a, long long b, long long pr)
	{
		if (b == 0)
			return 1 % pr;
		long long ans = 1 % pr;
		while (b)
		{
			if (b & 1)
				ans = (ans * a) % pr;
			b >>= 1;
			a = (a * a) % pr;
		}
		return ans;
	}
	int readInt()
	{
		int n = 0;
			scanf("%d",&n);
			return n;
		int ch = getcx(); int sign = 1;
		while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getcx(); }
	 
		while (ch >= '0' && ch <= '9')
			n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
		n = n * sign;
		return n;
	}
	long long readLong()
	{
		long long n = 0;
		//scanf("%lld",&n);
		//return n;
		int ch = getcx(); int sign = 1;
		while (ch < '0' || ch > '9') { if (ch == '-')sign = -1; ch = getcx(); }
	 
		while (ch >= '0' && ch <= '9')
			n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
		n = n * sign;
		return n;
	}
	long long inv_(long long val,long long pr=mod)
	{
		return fast(val, pr - 2, pr);
	}
}
char S[200001];
class solve
{

public:
	solve()	
	{
		scanf("%s",S);
		int n=strlen(S);
		int req=0;
		ve<ve<int> > Seq;
		ve<int> Taken,Nt;
		for(int i=0;i<n;i++)
		{
			if(S[i]=='1')
			{
				if(Taken.empty())
				{
					
					cout <<"-1";
					return;
				}
				int r=Taken.back();
				Seq[r].push_back(i);
				Taken.pop_back();
				Nt.push_back(r);
			}
			else
			{
				if(Nt.empty())
				{
					int r=Seq.size();
					Seq.push_back(ve<int>());
					Seq[r].push_back(i);
					Taken.push_back(r);
				}
				else
				{
					int r=Nt.back();
					Nt.pop_back();
					Seq[r].push_back(i);
					Taken.push_back(r);
				}
			}
		}
		if(!Nt.empty())
		{
			cout <<"-1";
			return;
		}
		cout << static_cast<int>(Seq.size()) << endl;
		for(auto &x:Seq)
		{
			cout << static_cast<int>(x.size()) << " ";
			for(auto &y:x)
			{
				cout << y+1<<" ";
			}
			cout << endl;
		}
	}

};

int32_t main()
{
	int t = 1, i = 1;
	//freopen("C:\\Users\\Xenor\\Downloads\\B.in","r",stdin);
	//freopen("C:\\Users\\Xenor\\Downloads\\gb2.txt","w",stdout);
	if (code_chef)
		scanf("%d", &t);
	while (t--)
	{
		if (code_jam)
			printf("Case #%d: ", i++);
		new solve;
	}
 
	return 0;
}