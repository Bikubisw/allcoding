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
BinaryTreeNode<int>* buildtreehelper(int* pre,int *post,int prestart,int preend,int poststart,int postend){
	if(poststart>postend){
		return NULL;
	}
	int rootdata=pre[prestart];
	int findindex=-1;
	int val=pre[prestart+1];
	for(int i=poststart;i<=postend;i++){
		if(post[i]==val){
		findindex=i;
		break;
		}
	}
	int lprestart=prestart+1;
	int lpoststart=poststart;
	int lpostend=findindex;
	int lpreend=(lprestart+lpostend)-lpoststart; 
	int rprestart=lpreend+1;
	int rpreend=preend;
	int rpoststart=lpostend+1;
	int rpostend=postend-1;
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(rootdata);
	root->left=buildtreehelper(pre,post,lprestart,lpreend,lpoststart,lpostend);
	root->right=buildtreehelper(pre,post,rprestart,rpreend,rpoststart,rpostend);
	return root;
}
BinaryTreeNode<int>* buildtree(int *pre,int * post,int n){
	return buildtreehelper(pre,post,0,n-1,0,n-1);
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
    //IOS;
    int n;
    cin>>n;
    int *preorder=new int[n];
    int* postorder=new int[n];
    for(int i=0;i<n;i++){cin>>postorder[i];}
    for(int i=0;i<n;i++){cin>>preorder[i];}
    BinaryTreeNode<int>*root=buildtree(preorder,postorder,n);
    display(root);
    delete root;
    delete[] postorder;
    delete[] preorder;
    return 0;
}
