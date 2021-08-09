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
struct Node{
	int ele;
	int i;
	int j;
};
struct compare{
	bool operator()(Node &a,Node&b){
		return a.ele>b.ele;
	}
};
int main()
{
    IOS;
    int k;
    cin>>k;
    vector<vector<int>>input;
    for(int i=0;i<k;i++){
		int a;
		cin>>a;
		vector<int>curr;
		for(int i=0;i<a;i++){
			int ele;
			cin>>ele;
			curr.pb(ele);
		}
		input.pb(curr);
	}
	priority_queue<Node,vector<Node>,compare>pq;
	for(int i=0;i<(int)input.size();i++){
		pq.push({input[i][0],i,0});
	}
	vector<int>ans;
	while(!pq.empty()){
		Node top=pq.top();
		pq.pop();
		ans.pb(top.ele);
		int k=top.i;
		int l=top.j;
		if(l+1<(int)input[k].size()){
			pq.push({input[k][l+1],k,l+1});
		}
	}
	for(auto &i:ans){
		cout<<i<<" ";
	}
	cout<<endl;



    return 0;
}
