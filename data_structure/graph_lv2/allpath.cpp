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
void path(vector<vector<int>>&graph,vector<bool>visited,int sv,int ev,string output){
	if(sv==ev){
		cout<<output<<endl;
		return;
	}
	visited[sv]=true;
	for(int it:graph[sv]){
		if(visited[it])continue;
		path(graph,visited,it,ev,output+to_string(it));
	}
	visited[sv]=false;
}
int main()
{
    IOS;
	int n,e;
	cin>>n>>e;
	vector<vector<int>>graph(n);
	for(int i=0;i<e;i++){
		int f,s,wei;
		cin>>f>>s>>wei;
		graph[f].pb(s);
		graph[s].pb(f);
	}
	vector<bool>visited(n,false);
	int sv,ev;
	cin>>sv>>ev;
	path(graph,visited,sv,ev,to_string(sv));
    return 0;
}
