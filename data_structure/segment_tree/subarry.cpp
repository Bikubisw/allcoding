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
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
struct node{
	int sum;
	int bestpresum;
	int bestsuffsum;
	int maxsum;
};
void buildtree(int*arr,node* tree,int start,int end,int treeindex){
	if(start==end){
		tree[treeindex].sum=arr[start];
		tree[treeindex].bestpresum=arr[start];
		tree[treeindex].bestsuffsum=arr[start];
		tree[treeindex].maxsum=arr[start];
		return;
	}
	int mid=(start+end)>>1;
	buildtree(arr,tree,start,mid,2*treeindex+1);
	buildtree(arr,tree,mid+1,end,2*treeindex+2);
	node left=tree[2*treeindex+1];
	node right=tree[2*treeindex+2];
	tree[treeindex].sum=left.sum+right.sum;
	tree[treeindex].bestpresum=max(left.bestpresum,left.sum+right.bestpresum);
	tree[treeindex].bestsuffsum=max(right.bestsuffsum,right.sum+left.bestsuffsum);
	tree[treeindex].maxsum=max({left.maxsum,right.maxsum,left.sum+right.bestpresum,right.sum+left.bestsuffsum,left.bestsuffsum+right.bestpresum});
}
node query(node* tree,int start,int end,int treeindex,int lefty,int righty){
	if(start>righty||end<lefty){
		return {-1000000,-1000000,-1000000,-1000000};
	}
	if(start>=lefty&&end<=righty){
		return tree[treeindex];
	}
	int mid=(start+end)>>1;
	node left=query(tree,start,mid,2*treeindex+1,lefty,righty);
	node right=query(tree,mid+1,end,2*treeindex+2,lefty,righty);
	node finalans;
	finalans.sum=left.sum+right.sum;
	finalans.bestpresum=max(left.bestpresum,left.sum+right.bestpresum);
	finalans.bestsuffsum=max(right.bestsuffsum,right.sum+left.bestsuffsum);
	finalans.maxsum=max({left.maxsum,right.maxsum,left.sum+right.bestpresum,right.sum+left.bestsuffsum,left.bestsuffsum+right.bestpresum});
	return finalans;
}
int main()
{
    IOS;
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    node* tree=new node[4*n];
    buildtree(arr,tree,0,n-1,0);
    int q;
    cin>>q;
    while(q--){
		int f,s;
		cin>>f>>s;
		f--,s--;
		node ans=query(tree,0,n-1,0,f,s);
		cout<<ans.maxsum<<endl;
	}
    delete[] tree;
    delete[] arr;
    return 0;
}
