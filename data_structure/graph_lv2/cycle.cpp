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
	auto havecycle=[&](vector<bool>&visited,int sv)->bool{
		queue<int>pending;
		pending.push(sv);
		while(!pending.empty()){
			int front=pending.front();
			pending.pop();
			if(!visited[front]){
				visited[front]=true;
				for(auto it:graph[front]){
					if(!visited[it]){
						pending.push(it);
					}
				}
			}else{
				return true;
			}
		}
		return false;
	};
    vector<bool>visited(n);
    bool flag=false;
    for(int i=0;i<n;i++){
		if(!visited[i]&&havecycle(visited,i)){
			flag=true;
			break;
		}
	}
    puts(flag?"true":"false");
    return 0;
}
