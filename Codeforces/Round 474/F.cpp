/*input
3 3
3 1 3
1 2 1
2 3 2
*/

// author : ShivamKD
#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define in(x) scanf("%d",&x);
const ll MOD = 1e9 + 7;
const int sz = 100010;

struct DynamicSegTree{

	DynamicSegTree *leftChild, *rightChild;
	int val;
	
	DynamicSegTree(int v, DynamicSegTree *left, DynamicSegTree *right){
		val =  v;
		leftChild = left;
		rightChild = right;
	}
};

DynamicSegTree* roots[sz];

void update(DynamicSegTree *current, int start, int end,int index,int val){
	if(start == end){
		current->val = max(current->val,val);
		return ;
	}

	if(start > end){
		return ;
	}
	int mid = (start + end) >> 1;

	if(current->leftChild == NULL) current->leftChild = new DynamicSegTree(0,NULL,NULL);
	if(current->rightChild == NULL) current->rightChild = new DynamicSegTree(0,NULL,NULL);

	if(index <= mid){
		update(current->leftChild,start,mid,index,val);
	}
	else
		update(current->rightChild,mid+1,end,index,val);

	current->val = max(current->leftChild->val,current->rightChild->val);
}


int query(DynamicSegTree *current, int qlow,int qhigh, int start, int end){
	//cout<<"I am in query\n";
	if(current== NULL || qlow > end || qhigh < start || start > end) return 0;

	if(qlow <= start and end <= qhigh){
		return current->val;
	}

	int mid = (start + end)>>1;

	return max(query(current->leftChild,qlow,qhigh,start,mid),query(current->rightChild, qlow, qhigh, mid + 1, end)); 
}

int Graph[sz][3];

int main(){
	
	int n,m;
	in(n);
	in(m);
    //cout<<"I am in main\n";
    
	for(int i = 1;i<=m;i++){

		in(Graph[i][0]);
		in(Graph[i][1]);
		in(Graph[i][2]);
		Graph[i][2] += 5;
	}
	
	for(int i = 1;i<=n;i++){
	    roots[i] = new DynamicSegTree(0,NULL,NULL);
	}

	for(int i = 1;i<=m;i++){

		int from = Graph[i][0];
		int count = query(roots[from],1,Graph[i][2]-1,1,sz);
		int to = Graph[i][1];
		update(roots[to],1,sz,Graph[i][2],count+1);

	}

	int answer = 0;

	for(int i = 1;i<=n;i++){
		answer = max(answer,roots[i]->val);
	}

	printf("%d\n", answer);

	return 0;
}