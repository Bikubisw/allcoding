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
class BinaryTreeNode{
	public:
	T data;
	BinaryTreeNode<T>*left;
	BinaryTreeNode<T>*right;
	BinaryTreeNode(T data){
		this->data=data;
		this->left=NULLM9U \\;
		this->right=NULL;
	}
	~BinaryTreeNode(){
		delete left;
		delete right;
	}
};
BinaryTreeNode<int>* takeinput(){
	int rootdata;
	cin>>rootdata;
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
	queue<BinaryTreeNode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		BinaryTreeNode<int>*front=pendingnodes.front();
		pendingnodes.pop();
		int leftdata;
		cin>>leftdata;
		if(leftdata!=-1){
			BinaryTreeNode<int>*leftchild=new BinaryTreeNode<int>(leftdata);
			front->left=leftchild;
			pendingnodes.push(leftchild);
		}
		int rightdata;
		cin>>rightdata;
		if(rightdata!=-1){
			BinaryTreeNode<int>*rightchild=new BinaryTreeNode<int>(rightdata);
			front->right=rightchild;
			pendingnodes.push(rightchild);
		}
	}
	return root;
}
pair<int,int>diameterhelper(BinaryTreeNode<int>*root){
	if(root==NULL){
		pair<int,int>p;
		p.first=0;
		p.second=0;
		return p;
	}
	pair<int,int>leftans=diameterhelper(root->left);
	pair<int,int>rightans=diameterhelper(root->left);
	int hei=1+max(leftans.first,rightans.first);
	int dia=max(leftans.first+rightans.first,max(leftans.second,rightans.second));
	pair<int,int>finalans;
	finalans.first=hei;
	finalans.second=dia;
	return finalans;
	
	}
int diameter(BinaryTreeNode<int>*root){
	return diameterhelper(root).second;
}
int main()
{
    IOS;
	BinaryTreeNode<int>*root=takeinput();
	cout<<diameter(root);
	delete root;
    return 0;
}
