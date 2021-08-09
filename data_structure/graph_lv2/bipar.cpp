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
#define sz(v) ((int)(v).size())
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
bool isbipar(vector<vector<int>>&graph,vector<int>&color,int sv){
	//using BFS:------
	//queue<int>pen;
	//color[sv]=1;
	//pen.push(sv);
	//while(!pen.empty()){
		//int front=pen.front();
		//pen.pop();
		//for(int it:graph[front]){
			//if(color[it]==-1){
				//color[it]=1-color[front];
				//pen.push(it);
			//}else if(color[front]==color[it])return false;
		//}
	//}
	//return true;
	
	// using DFS------
	if(color[sv]==-1)color[sv]=1;
	for(int i:graph[sv]){
		if(color[i]==-1){
		color[i]=1-color[sv];
		bool ans=isbipar(graph,color,i);
		if(!ans)return false;
	}
	else if(color[sv]==color[i])return false;
	}
	return true;
}
int main()
{
    IOS;
    int n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n);
    for(int i=0;i<e;i++){
		int f,s,w;
		cin>>f>>s>>w;
		graph[f].pb(s);
		graph[s].pb(f);
	}
	vector<int>color(n,-1);
	bool flag=true;
	for(int i=0;i<n;i++){
	if(color[i]==-1&&!isbipar(graph,color,i)){
		flag=false;
		break;
	}
	}
	puts(flag?"true":"false");
    return 0;
}
