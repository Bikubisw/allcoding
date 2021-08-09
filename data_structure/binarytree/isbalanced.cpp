#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<cfloat>
#include<unordered_set>
#include <unordered_map>
#include<string>
#include <cstring>
#include<stack>
#include<queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include<cassert>
#include<utility>
#include<unordered_set>
#include<set>
#include<cmath>
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
template<typename T>
class BianaryTreeNode{
public:
	T data;
	BianaryTreeNode<T>* left;
	BianaryTreeNode<T>* right;
	BianaryTreeNode(T data){
		this->data=data;
		left=NULL;
		right=NULL;
	}
	~BianaryTreeNode(){
		delete left;
		delete right;
	}

};
BianaryTreeNode<int>* takeinputlevelwise(){
	int rootdata;
	cin>>rootdata;
	BianaryTreeNode<int>* root=new BianaryTreeNode<int>(rootdata);
	queue<BianaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		BianaryTreeNode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int lchild,rchild;
		cin>>lchild;
		if(lchild!=-1){
			BianaryTreeNode<int>* lnode=new BianaryTreeNode<int>(lchild);
			front->left=lnode;
			pendingnodes.push(lnode);
		}
		cin>>rchild;
		if(rchild!=-1){
			BianaryTreeNode<int>* rnode=new BianaryTreeNode<int>(rchild);
			front->right=rnode;
			pendingnodes.push(rnode);
		}

	}
	return root;
}
struct Balanced{
	bool isbalanced;
	int hei;
};
Balanced balancedtree(BianaryTreeNode<int>*root){
	if(root==NULL){
		Balanced p;
		p.isbalanced=true;
		p.hei=0;
		return p;
	}
	Balanced leftans=balancedtree(root->left);
	Balanced rightans=balancedtree(root->right);
	Balanced finalans;
	finalans.hei=1+max(leftans.hei,rightans.hei);
	finalans.isbalanced=abs(leftans.hei-rightans.hei)>1?false:leftans.isbalanced&&rightans.isbalanced;
	return finalans;
}
int main()
{
    IOS;
 	BianaryTreeNode<int>* root=takeinputlevelwise();
 	if(balancedtree(root).isbalanced)cout<<"Tree is Balanced"<<endl;
 	else cout<<"Tree is not balanced"<<endl;
    return 0;
}