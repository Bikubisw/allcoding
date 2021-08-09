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
void printtree(BianaryTreeNode<int>*root){
	queue<BianaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	pendingnodes.push(NULL);
	while(!pendingnodes.empty()){
		BianaryTreeNode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		if(front==NULL){
			if(pendingnodes.empty())break;
			cout<<endl;
			pendingnodes.push(NULL);
			continue;
		}
		cout<<front->data<<" ";
		if(front->left){
			pendingnodes.push(front->left);
		}
		if(front->right){
			pendingnodes.push(front->right);
		}

}
}
void leftcloned(BianaryTreeNode<int>*root){
	if(root==NULL)return;
	leftcloned(root->left);
	leftcloned(root->right);
	BianaryTreeNode<int>* newnode=new BianaryTreeNode<int>(root->data);
	BianaryTreeNode<int>*tempnode=root->left;
	root->left=newnode;
	newnode->left=tempnode;
}
void leftcloned_to_normal(BianaryTreeNode<int>*root){
if(root==NULL){
	return;
}
leftcloned_to_normal(root->left->left);
leftcloned_to_normal(root->right);
BianaryTreeNode<int>* temp=root->left;
root->left=root->left->left;
temp->left=NULL;
delete temp;
}
void print_singlechild(BianaryTreeNode<int>* root){
	if(root==NULL)return;
	if((root->left!=NULL&&root->right==NULL)||(root->left==NULL&&root->right!=NULL)){
		if(root->left){
			cout<<root->left->data<<endl;
		}else{
			cout<<root->right->data<<endl;
		}
	}
	print_singlechild(root->left);
	print_singlechild(root->right);
}
BianaryTreeNode<int>* removeleafnodes(BianaryTreeNode<int>* root){
	if(root==NULL){
		return NULL;
	}
	if(root->left==NULL&&root->right==NULL){
		return NULL;
	}
	BianaryTreeNode<int>*leftoutput=removeleafnodes(root->left);
	BianaryTreeNode<int>* rightoutput=removeleafnodes(root->right);
	root->left=leftoutput;
	root->right=rightoutput;
	return root;


}
int main()
{
    IOS;
    BianaryTreeNode<int>*root=takeinputlevelwise();
    BianaryTreeNode<int>* root1=removeleafnodes(root);
    // leftcloned_to_normal(root);
    // printtree(root);
    //print_singlechild(root);
    printtree(root1);
    delete root;
 	return 0;
}