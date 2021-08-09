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
struct Pair{
	int tilt;
	int sum;
};
Pair tiltans(BianaryTreeNode<int>*root){
	if(root==NULL){
		Pair ans;
		ans.tilt=0;
		ans.sum=0;
		return ans;
	}
	Pair leftans=tiltans(root->left);
	Pair rightans=tiltans(root->right);
	Pair finalans;
	finalans.sum=root->data+leftans.sum+rightans.sum;
	finalans.tilt=leftans.tilt+rightans.tilt+abs(leftans.sum-rightans.sum);
	return finalans;
}
int main()
{
    IOS;
    BianaryTreeNode<int>*root=takeinputlevelwise();
    Pair ans=tiltans(root);
    cout<<ans.tilt<<endl;
    return 0;
}