/*input

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n,q,k,l,r;

struct Node{
	ll me ;
	struct Node *left,*right;
	ll val;
	Node(ll x){
		left = NULL;
		right = NULL;
		me = x;
		val = 0;
	}


};

Node *start = NULL;

void update(Node *curr,ll k, ll qlow,ll qhigh,ll low, ll high){
	
	if(!curr->left){
		curr->left = new Node(curr->me);

	}
	
	if(!curr->right){
		curr->right = new Node(curr->me);
	}


	if(qlow)

}


int main(){

	return 0;
}