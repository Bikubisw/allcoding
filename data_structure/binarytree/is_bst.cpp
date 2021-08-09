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
// int maximum(BianaryTreeNode<int>*root){
// 	if(root==NULL){
// 		return INT_MIN;
// 	}
// 	return max(root->data,max(maximum(root->left),maximum(root->right)));
// }
// int minimum(BianaryTreeNode<int>*root){
// 		if(root==NULL){
// 		return INT_MAX;
// 	}
// 	return min(root->data,min(minimum(root->left),minimum(root->right)));
// }
struct ISBST{
	int maximum;
	int minimum;
	bool isbst;
};
ISBST isbst(BianaryTreeNode<int>*root){
	if(root==NULL){
		ISBST ans;
		ans.minimum=INT_MAX;
		ans.maximum=INT_MIN;
		ans.isbst=true;
		return ans;
	}
	ISBST leftans=isbst(root->left);
	ISBST rightans=isbst(root->right);
	ISBST finalans;
	finalans.maximum=max(root->data,max(leftans.maximum,rightans.maximum));
	finalans.minimum=min(root->data,min(leftans.minimum,rightans.minimum));
	finalans.isbst=(root->data>leftans.maximum)&&(root->data<=rightans.minimum)&&(leftans.isbst)&&(rightans.isbst);
	return finalans;
}
bool isbsttree(BianaryTreeNode<int>*root,int max=INT_MAX,int min=INT_MIN){
	if(root==NULL)return true;
	if(root->data<min||root->data>max)return false;
	return isbsttree(root->left,root->data,min)&&isbsttree(root->right,max,root->data);
}
int main()
{
    IOS;
    BianaryTreeNode<int>* root=takeinputlevelwise();
    cout<<((isbsttree(root))?"IT IS A BST\n":"IT IS NOT a BST\n");
    return 0;
}