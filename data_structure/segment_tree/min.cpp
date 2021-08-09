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
	tree[treeindex]=min(tree[2*treeindex+1],tree[2*treeindex+2]);
}
void updatetree(vector<int>&arr,vector<int>&tree,int start,int end,int treeindex,int pos,int val){
	//assert(start==end);
	if(start==end){
		arr[start]=val;
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
	tree[treeindex]=min(tree[2*treeindex+1],tree[2*treeindex+2]);
	
}
int query(vector<int>&tree,int start,int end,int treeindex,int left,int right){
	//completely outside the range
	if(start>right||end<left){
		return INT_MAX;
	}
	//completely inside
	if(start>=left&&end<=right){
	return tree[treeindex];
	}
	//partially overlap
	int mid=(start+end)>>1;
	
	return min(query(tree,start,mid,2*treeindex+1,left,right),query(tree,mid+1,end,2*treeindex+2,left,right));
}
int main()
{
    IOS;
    int n,q;
    cin>>n>>q;
    vector<int>arr(n);
    for(auto&it:arr){
		cin>>it;
	}
	vector<int>tree(4*n);
	buildtree(arr,tree,0,n-1,0);
	char c;
	int l,r;
	while(q--){
		cin>>c>>l>>r;
		if(c=='q'){
			node ans=query(tree,0,n-1,0,l-1,r-1);
			cout<<ans.maxi+ans.smaxi<<endl;
		}else{
			updatetree(arr,tree,0,n-1,0,l-1,r);
		}
	}
    return 0;
}
