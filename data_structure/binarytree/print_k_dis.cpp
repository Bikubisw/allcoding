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
vector<BianaryTreeNode<int>*>* nodeto_root(BianaryTreeNode<int>*root,int k,int data){
	if(root==NULL)return NULL;
	if(root->data==data){vector<BianaryTreeNode<int>*> *output=new vector<BianaryTreeNode<int>*>();output->push_back(root);return output;}
	vector<BianaryTreeNode<int>*>* leftoutput=nodeto_root(root->left,k,data);
	if(leftoutput!=NULL){leftoutput->push_back(root);return leftoutput;}
	vector<BianaryTreeNode<int>*>* rightouptut=nodeto_root(root->right,k,data);
	if(rightouptut!=NULL){rightouptut->push_back(root);return rightouptut;}

	return NULL;

}
void print_atlevelk(BianaryTreeNode<int>*root,int k){
	if(root==NULL)return;
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	print_atlevelk(root->left,k-1);
	print_atlevelk(root->right,k-1);
}
int main()
{
    IOS;
    BianaryTreeNode<int>*root=takeinputlevelwise();
    int k,data;
    cin>>k>>data;
    vector<BianaryTreeNode<int>*>*output=nodeto_root(root,k,data);
    print_atlevelk(output->at(0),k); 
    for(int i=1;i<output->size();i++){
    	int remdist=k-i;
    	BianaryTreeNode<int>* curr=output->at(i);
    	BianaryTreeNode<int>* prev=output->at(i-1);
    	if(remdist==0){
    		cout<<curr->data<<endl;
    		return 0;
    	}
    	else{
    		if(prev==curr->left){
    			print_atlevelk(curr->right,remdist-1);
    		}else{
    			print_atlevelk(curr->left,remdist-1);
    		}


    	}
    }
    delete root;
    delete output;
    return 0;
}