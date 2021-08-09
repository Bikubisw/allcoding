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
template<typename T>
struct BinaryTreeNode{
	T data;
	BinaryTreeNode<T>*left;
	BinaryTreeNode<T>*right;
	BinaryTreeNode(T data){
		this->data=data;
		this->left=NULL;
		this->right=NULL;
	}
	~BinaryTreeNode(){
		delete left;
		delete right;
	}
};
BinaryTreeNode<int>*treebuilder(vector<int>&arr,int s,int e){
	if(s>e)return NULL;
	int mid=(s+e)>>1;
	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(arr[mid]);
	root->left=treebuilder(arr,s,mid-1);
	root->right=treebuilder(arr,mid+1,e);
	return root;
}
BinaryTreeNode<int>* bToDLL(BinaryTreeNode<int>* root){
	auto getallnodes=[&](BinaryTreeNode<int>*node,stack<BinaryTreeNode<int>*>&st){
		while(node!=NULL){
			st.push(node);
			node=node->left;
		}
	};
	stack<BinaryTreeNode<int>*>st;
	getallnodes(root,st);
	BinaryTreeNode<int>*dummy=new BinaryTreeNode<int>(-1);
	BinaryTreeNode<int>*prev=dummy;
	while(!st.empty()){
		BinaryTreeNode<int>*curr=st.top();
		st.pop();
		curr->left=prev;
		prev->right=curr;
		prev=curr;
		getallnodes(curr->right,st);
	}
	BinaryTreeNode<int>*head=dummy->right;
	head->left=NULL;
	dummy->right=NULL;
	head->left=prev;
	prev->right=head;
	return head;
}
void print(BinaryTreeNode<int>*head){
	BinaryTreeNode<int>*temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->right;
		if(temp==head)break;
	}
}
int main()
{
    IOS;
	int n;
	cin>>n;
	vector<int>arr(n);
	for(auto&it:arr)cin>>it;
	BinaryTreeNode<int>*root=treebuilder(arr,0,n-1);
	BinaryTreeNode<int>*head=bToDLL(root);
	print(head);
	cout<<endl;
	//dbg(1);
	//delete head;
    return 0;
}
