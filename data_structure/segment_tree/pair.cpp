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
struct node {
	int maxi;
	int smaxi;
};
void buildtree(vector<int>&arr,vector<node>&tree,int start,int end,int treeindex){
	if(start==end){
		tree[treeindex].maxi=arr[start];
		tree[treeindex].smaxi=INT_MIN;
		return;
	}
	int mid=(start+end)>>1;
	buildtree(arr,tree,start,mid,2*treeindex+1);
	buildtree(arr,tree,mid+1,end,2*treeindex+2);
	node left=tree[2*treeindex+1];
	node right=tree[2*treeindex+2];
	tree[treeindex].maxi=max(left.maxi,right.maxi);
	tree[treeindex].smaxi=min(max(left.maxi,right.smaxi),max(right.maxi,left.smaxi));
}
node query(vector<node>&tree,int start,int end,int treeindex,int left,int right){
	if(start>right||end<left){
		node ans;
		ans.maxi=INT_MIN;
		ans.smaxi=INT_MIN;
		return ans;
	}
	if(start>=left&&end<=right){
		return tree[treeindex];
	}
	int mid=(start+end)>>1;
	node ans1=query(tree,start,mid,2*treeindex+1,left,right);
	node ans2=query(tree,mid+1,end,2*treeindex+2,left,right);
	node finalans;
	finalans.maxi=max(ans1.maxi,ans2.maxi);
	finalans.smaxi=min(max(ans1.maxi,ans2.smaxi),max(ans1.smaxi,ans2.maxi));
	return finalans;
}
void updatetree(vector<int>&arr,vector<node>&tree,int start,int end,int treeindex,int pos,int val){
	if(start==end){
		arr[pos]=val;
		tree[treeindex].maxi=val;
		tree[treeindex].smaxi=INT_MIN;
		return;
	}
	int mid=(start+end)>>1;
	if(pos>mid){
		updatetree(arr,tree,mid+1,end,2*treeindex+2,pos,val);
	}else{
		updatetree(arr,tree,start,mid,2*treeindex+1,pos,val);
	}
	node left=tree[2*treeindex+1];
	node right=tree[2*treeindex+2];
	tree[treeindex].maxi=max(left.maxi,right.maxi);
	tree[treeindex].smaxi=min(max(left.maxi,right.smaxi),max(right.maxi,left.smaxi));
}
int main()
{
    IOS;
    int n,q;
    cin>>n;
    vector<int>arr(n);
    for(auto&it:arr){
		cin>>it;
	}
	cin>>q;
	vector<node>tree(4*n);
	buildtree(arr,tree,0,n-1,0);
	char c;
	int l,r;
	while(q--){
		cin>>c>>l>>r;
		if(c=='Q'){
			node ans=query(tree,0,n-1,0,l-1,r-1);
			cout<<ans.maxi+ans.smaxi<<endl;
		}else{
			updatetree(arr,tree,0,n-1,0,l-1,r);
		}
	}

    return 0;
}
