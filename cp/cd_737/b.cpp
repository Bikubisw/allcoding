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
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define sz(v) ((int)(v).size())
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n);
	for(auto&it:arr)cin>>it;
	if(k==n){
		puts("YES");
		continue;
	}
	int sp=0;
	int i=0;
	int gp=0;
	for (;i<n-1;i++){
		while(arr[i]<=arr[i+1]&&i<n-1){
			sp++;
			i++;
		}
		if()
		
	}
	if(sp>0)++sp;
	int g=n-sp;
	dbg(g);
	bool flag=true;
	if(g>k)flag=false;
	
	puts(flag?"YES":"NO");
    }
    return 0;
}
