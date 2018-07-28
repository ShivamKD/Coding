/*input
10
331415699 278745619 998190004 423175621 42983144 166555524 843586353 802130100 337889448 685310951
226011312 266003835 342809544 504667531 529814910 684873393 817026985 844010788 993949858 1031395667
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x)

typedef struct Node{
	struct Node *One,*Zero;
	int count;

	Node(){
		One = Zero = NULL;
		count = 0;
	}


}trieDS;


trieDS *root = NULL;

string DecimalToBinary(ll n){
	string s = "";
	for(int i =29;i>=0;i--){
		if(n&(1<<i))
			s = s + "1";
		else
			s = s + "0";
	}
	return s;
}

void insert(string s){

	trieDS *ptr = root;

	int i = 0;

	while(i<30){
		char c = s[i];
		ptr->count = ptr->count + 1;

		if(c=='1'){
			if(!ptr->One)
				ptr->One = new trieDS();
			ptr = ptr->One;
		}
		else{
			if(!ptr->Zero)
				ptr->Zero = new trieDS();
			ptr = ptr->Zero;
		}

		i++;
	}

	ptr->count = ptr->count+1;
}


ll query(string s){
	ll ans = 0;
	int i = 0;
	trieDS *ptr = root;

	while(i<30){
		char c = s[i];
		ptr->count = ptr->count - 1;
		if(c=='1'){
			if(ptr->One){
				if(ptr->One->count){
					ptr = ptr->One;
				}
				else{
					ptr = ptr->Zero;
					ans += (1<<(29-i));
				}
			}
			else{
				ptr = ptr->Zero;
				ans += (1<<(29-i));
			}
		}
		else{
			if(ptr->Zero){
				if(ptr->Zero->count){
					ptr = ptr->Zero;
				}
				else{
					ptr = ptr->One;
					ans += (1<<(29-i));
				}
			}
			else{
				ptr = ptr->One;
				ans += (1<<(29-i));
			}
		}
		i++;
	}
	ptr->count = ptr->count - 1;
	return ans;
}


int main(){
	ll n;
	in(n);
	ll a[n],b;
	for (int i = 0; i < n; ++i)
	{
		in(a[i]);
	}

	root = new trieDS();

	for (int i = 0; i < n; ++i)
	{
		in(b);
		insert(DecimalToBinary(b));
	}
	//cout<<root->count<<" ";
	for (int i = 0; i < n; ++i)
	{
		printf("%lld ",query(DecimalToBinary(a[i])) );
	}
	return 0;
}