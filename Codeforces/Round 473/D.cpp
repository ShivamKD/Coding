/*input
3
3 18 2
*/

// author : ShivamKD

#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define ll long long
#define in(x) scanf("%lld",&x)
#define loop(start,end) for(ll var = start; var < end; var++)
#define arr(a,n) loop(0,n) in(a[var])
#define parr(a,n) loop(0,n) printf("%lld ", a[var]);
const ll MOD = 1e9 + 7;

const int sz = 4 * 1299721 ;

int Factor[sz];
int primes[sz];
int check[sz];

int counter = 0;


void pre(){

	for(int i = 1;i<sz;i++){
		if(i%2){
			Factor[i]  = i;
		}
		else{
			Factor[i] = 2;
		}
	}

	for(int i = 3;i*i<sz;i+=2){
		if(Factor[i]==i){
			for(int j = i*i;j<sz;j+=i){
				if(Factor[j]==j){
					Factor[j] = i;
				}
			}
		}
	}
	Factor[1] = 0;
	for(int i = 2;i<sz;i++){
		if(Factor[i] == i){
			primes[counter] = i;
			counter++;
			//cout<<i<<" ";
		}
	}

}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	pre();

	int n;
	int x;

	cin>>n;

	for(int i = 0;i<n;i++){
		cin>>x;

		assert(1<=x and x<=100000);

		int dup = x;

		int k = 0;
		while(x!=1){
			if(check[Factor[x]]){
				k = 1;
				break;
			}
			x = x / Factor[x];
		}

		x = dup;
		while(x!=1){

			int y = Factor[x];

			if(check[y]){

				int current = 0;

				for(int j = dup+1;;j++){

					int dupM = j;
					int flag = 0;

					while(dupM!=1){
						if(check[Factor[dupM]])
						{
							flag = 1;
							break;
						}
						dupM = dupM / Factor[dupM];
					}

					if(!flag){
						cout<<j<<" ";
						dupM = j;
						while(dupM!=1){
							check[Factor[dupM]] = 1;
							dupM = dupM / Factor[dupM];
						}
						break;
					}

				}

				i++;

				for(;i<n;i++){

					while(check[primes[current]]){
						current++;
					}

					cout<<primes[current]<<" ";

					check[primes[current]] = 1;
					current++;

				}

				return 0;
			}
			if(!k)
			check[y] = 1;

			while(Factor[x] == y){
				x = x / Factor[x];
			}
		}
		cout<<dup<<" ";
	}
	//cout<<"\n"<<counter<<"";

	return 0;
}