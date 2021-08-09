#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
#include <string>
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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
void buildtree(vector<int>&arr,vector<int>&tree,int start,int end,int treeindex){
	if(start==end){
	tree[treeindex]=arr[start];
	return;	
	}
	int mid=(start+end)>>1;
	buildtree(arr,tree,start,mid,2*treeindex+1);
	buildtree(arr,tree,mid+1,end,2*treeindex+2);
	tree[treeindex]=tree[2*treeindex+1]+tree[2*treeindex+2];
}
int query(vector<int>&tree,int start,int end,int treeindex,int left,int right){
	//completely outside the range
	if(start>right||end<left){
		return 0;
	}
	//completely inside
	if(start>=left&&end<=right){
	return tree[treeindex];	
	}
	//partially overlap
	int mid=(start+end)>>1;
	
	return query(tree,start,mid,2*treeindex+1,left,right)+query(tree,mid+1,end,2*treeindex+2,left,right);
}
void updatetree(vector<int>&arr,vector<int>&tree,int start,int end,int treeindex,int pos,int val){
	//assert(start==end);
	if(start==end){
		arr[pos]=val;
		tree[treeindex]=val;
		return;
	}
	
	int mid=(start+end)>>1;
	if(pos>mid){
		updatetree(arr,tree,mid+1,end,2*treeindex+2,pos,val);
	}
	else{
		updatetree(arr,tree,start,mid,2*treeindex+1,pos,val);
	}
	tree[treeindex]=tree[2*treeindex+1]+tree[2*treeindex+2];
	
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &it:arr){
		cin>>it;
	}
	vector<int> tree(2*n-1);
	buildtree(arr,tree,0,n-1,0);
	/*int left,right;
	cin>>left>>right;
	left--;right--;
	//cout<<query(tree,0,n-1,0,left,right)<<endl;*/
	for(auto &it:tree){
		cout<<it<<" ";
	}
	cout<<endl;
	int pos,val;
	cin>>pos>>val;
	pos--;
	updatetree(arr,tree,0,n-1,0,pos,val);
	for(auto &it:tree){
		cout<<it<<" ";
	}
	cout<<endl;
    return 0;
}
