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
			left=NULL;
			right=NULL;
		}
		~BinaryTreeNode(){
			delete left;
			delete right;
		}
};
BinaryTreeNode<int>* buildtreehelper(int* pre,int *in,int instart,int inend,int prestart,int preend){
	if(instart>inend){
		return NULL;
	}
	int rootdata=pre[prestart];
	int rootindex=-1;
	for(int i=instart;i<=inend;i++){
		if(in[i]==rootdata){
			rootindex=i;
			break;
		}
	}
	int linstart=instart;
	int linend=rootindex-1;
	int lprestart=prestart+1;
	int lpreend=lprestart+linend-linstart;
	int rinstart=rootindex+1;
	int rinend=inend;
	int rprestart=lpreend+1;
	int rpreend=preend;
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
	root->left=buildtreehelper(pre,in,linstart,linend,lprestart,lpreend);
	root->right=buildtreehelper(pre,in,rinstart,rinend,rprestart,rpreend);
	return root;
}
BinaryTreeNode<int>* buildtree(int *pre,int * in,int n){
	return buildtreehelper(pre,in,0,n-1,0,n-1);
}
void display(BinaryTreeNode<int> *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->data) : "."));
    str += (" -> " + to_string(node->data) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->data) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}
int main()
{
    IOS;
    int n;
    cin>>n;
    int* preorder=new int[n];
    int *inorder=new int[n];
    for(int i=0;i<n;i++)cin>>preorder[i];
    for(int i=0;i<n;i++)cin>>inorder[i];
    BinaryTreeNode<int>*root=buildtree(preorder,inorder,n);
    display(root);
    
    delete root;
    delete[] preorder;
    delete[] inorder;
    return 0;
}
