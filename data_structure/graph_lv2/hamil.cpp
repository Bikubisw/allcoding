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
#define MOD 1000000007
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
void allpaths(vector<vector<array<int,3>>>&graph,int n,int sv,set<int>&visited,int ori,string output){
	if((int)visited.size()==n-1){
		bool flag=false;
		for(auto& it:graph[sv]){
			if(it[1]==ori){
				flag=true;
				break;
			}
		}
		if(flag)cout<<output<<"*"<<endl;
		else cout<<output<<"."<<endl;
		return;
	}
	visited.insert(sv);
	for(auto &it:graph[sv]){
		if(visited.count(it[1])==0){
			allpaths(graph,n,it[1],visited,ori,output+to_string(it[1]));
		}
	}
	visited.erase(sv);
}
int main()
{
    IOS;
	int n,e;
	cin>>n>>e;
	vector<vector<array<int,3>>>graph(n);
	for(int i=0;i<e;i++){
		int f,s,wei;
		cin>>f>>s>>wei;
		array<int,3>a={f,s,wei};
		array<int,3>b={s,f,wei};
		graph[f].eb(a);
		graph[s].eb(b);
	}
    int sv;
 	cin>>sv;
 	int orgin=sv;
 	set<int> visited;
 	allpaths(graph,n,sv,visited,orgin,to_string(sv));
    
    return 0;
}
