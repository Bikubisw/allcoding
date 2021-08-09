#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cassert>
#include <utility>
#include <unordered_set>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#include <numeric>
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define dbg(x) cerr<<"["<<x<<"]"<<","<<endl;
#define dbg1(x,y) cerr<<"["<<x<<","<<y<<"]"<<","<<endl;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sf(n) scanf("%d",&n);
#define sfl(n) scanf("%ld",&n);
#define sfll(n) scanf("%lld",&n);
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
class Node{
	public:
	Node* left;
	Node* right;
	int data;
	int height;
	Node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
		this->height=1;
	}
	~Node(){
		if(left)delete left;
		if(right)delete right;
	}
	
};
class BST{
	public:
	Node* root;
	BST(){
		root=NULL;
	}
	~BST(){
		delete root;
	}
	Node* insertTree(Node* root,int data){
		if(root==NULL){
			Node* newnode=new Node(data);
			return newnode;
		}
		if(data<root->data){
			root->left=insertTree(root->left,data);
		}
		else if(data>=root->data){
			root->right=insertTree(root->right,data);
		}
		int lht=height(root->left),rht=height(root->right);
		root->height=max(lht,rht)+1;
		int diff=lht-rht;
		Node* newroot=root;
		if(diff>1){
			if(data<root->left->data){//LL
				newroot=rightrotate(root);
			}else if(data>root->left->data){//LR
				root->left=leftrotate(root->left);
				newroot=rightrotate(root);
			}
		}else if(diff<-1){
			if(data<root->right->data){//RL
				root->right=rightrotate(root->right);
				newroot=leftrotate(root);
			}else if(data>root->right->data){//RR
				newroot=leftrotate(root);
			}
		}
		return newroot;
	}
	void insertTree(int data){
		this->root=insertTree(root,data);
	}
	Node* deleteNode(Node* root,int data){
		if(root==NULL)return NULL;
		if(data<root->data){
			root->left=deleteNode(root->left,data);
			return root;
		}
		if(data>root->data){
			root->right=deleteNode(root->right,data);
			return root;
		}
		else{
			if(root->left==NULL&&root->right==NULL){
				delete root;
				return NULL;
			}else if(root->left==NULL){
				Node* temp=root->right;
				root->right=NULL;
				delete root;
				return temp;
				
			}else if(root->right==NULL){
				Node* temp=root->left;
				root->left=NULL;
				delete root;
				return temp;
				
			}else{
				Node* minnode=root->right;
				while(minnode->left!=NULL){minnode=minnode->left;}
				int mindata=minnode->data;
				root->data=mindata;
				root->right=deleteNode(root->right,mindata);
				return root;
			}
		}
		int lht=height(root->left),rht=height(root->right);
		root->height=max(lht,rht)+1;
		int diff=lht-rht;
		Node* newroot=root;
		if(diff>1){
			int delta=height(root->left->left)-height(root->left->right);
			if(delta>=0){
				newroot=rightrotate(root);
			}else if(delta<0){
				root->left=leftrotate(root->left);
				newroot=rightrotate(root);
				
			}
		}else if(diff<-1){
			int delta=height(root->right->left)-height(root->right->right);
			if(delta>0){
				root->right=rightrotate(root->right);
				newroot=leftrotate(root);
			}else if(delta<=0){
				newroot=leftrotate(root);	
			}
		}
		return newroot;	
	}
	void deleteNode(int data){
		this->root=deleteNode(root,data);
	}
	int height(Node* root){
		if(root==NULL)return 0;
		return root->height;
	}
	Node* leftrotate(Node *a){
		Node*b=a->right;
		Node* t2=b->left;
		b->left=a;
		a->right=t2;
		a->height=max(height(a->left),height(a->right))+1;
		b->height=max(height(b->left),height(b->right))+1;
		return b;
	}
	Node* rightrotate(Node *a){
		Node*b=a->left;
		Node* t2=b->right;
		b->right=a;
		a->left=t2;
		a->height=max(height(a->left),height(a->right))+1;
		b->height=max(height(b->left),height(b->right))+1;
		return b;
	}
	
};
int main()
{
    IOS;
    
	
	
    return 0;
}
