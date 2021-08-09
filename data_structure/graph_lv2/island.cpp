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
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void mark(vector<vector<int>>&arr,vector<vector<int>>&visited,int r,int c,int i,int j){
	if(i==r||i<0||j==c||j<0||visited[i][j]||arr[i][j]==1){
		return;
	}
	visited[i][j]=true;
	for(int k=0;k<4;k++){
	mark(arr,visited,r,c,i+dx[k],j+dy[k]);
	}
}
int main()
{
    IOS;
	int r,c;
	cin>>r>>c;
	vector<vector<int>>arr(r,vector<int>(c));
	for(auto&it:arr)for(auto&i:it)cin>>i;
	vector<vector<int>>visited(r,vector<int>(c,false));
	int count=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]==0&&!visited[i][j]){
				count++;
				mark(arr,visited,r,c,i,j);
			}
		}
	}
    cout<<count<<endl;
    return 0;
}
