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
int idx;
BinaryTreeNode<int>* buildtree(vector<int>&arr,int start=INT_MIN,int end=INT_MAX){
	if(idx==-1||arr[idx]<start||arr[idx]>end){
		return NULL;
	}
	BinaryTreeNode<int>*root=new BinaryTreeNode<int>(arr[idx--]);
	root->right=buildtree(arr,root->data,end);
	root->left=buildtree(arr,start,root->data);
	return root;
}
BinaryTreeNode<int>*buildtreehelper(vector<int>&arr){
	idx=arr.size()-1;
	return buildtree(arr);
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
    vector<int>arr(n);
    for(auto&it:arr)cin>>it;
    BinaryTreeNode<int>*root=buildtreehelper(arr);
    display(root);
    delete root;
    return 0;
}
