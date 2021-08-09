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
struct LargestBSTnode
{
	int maximum;
	int minimum;
	int count;
	bool isbst;
	BianaryTreeNode<int>* node;
};
LargestBSTnode largestbstnode(BianaryTreeNode<int>* root){
	if(root==NULL){
		LargestBSTnode ans;
		ans.maximum=INT_MIN;
		ans.minimum=INT_MAX;
		ans.isbst=true;
		ans.count=0;
		ans.node=NULL;
		return ans;
	}
	LargestBSTnode leftans=largestbstnode(root->left);
	LargestBSTnode rightans=largestbstnode(root->right);
	LargestBSTnode finalans;
	finalans.maximum=max(root->data,max(leftans.maximum,rightans.maximum));
	finalans.minimum=min(root->data,min(leftans.minimum,rightans.minimum));
	bool ISbst=(root->data>leftans.maximum)&&(root->data<=rightans.minimum)&&(leftans.isbst)&&(rightans.isbst);
	if(ISbst){
		finalans.node=root;
		finalans.count=1+leftans.count+rightans.count;
	}else if(leftans.count>rightans.count){
		finalans.count=leftans.count;
		finalans.node=leftans.node;

	}else{
		finalans.count=rightans.count;
		finalans.node=rightans.node;
	}
	finalans.isbst=ISbst;
	return finalans;
}
int main()
{
    IOS;
    BianaryTreeNode<int>*root=takeinputlevelwise();
    LargestBSTnode ans=largestbstnode(root);
    cout<<ans.node->data<<"@"<<ans.count<<endl;
    return 0;
}