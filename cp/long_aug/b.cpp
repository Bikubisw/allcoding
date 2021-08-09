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
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	map<int,int>mp;
	for(int i=0;i<4;i++){
		int x;cin>>x;
		++mp[x];
	}
	if(mp.size()==1){
	cout<<0<<endl;
		}else if(mp.size()>2){
			cout<<2<<endl;
		}
		else{
			auto it=mp.begin();
			int h=it->second;
			++it;
			int k=it->second;
			if(h==k)cout<<2<<endl;
			else cout<<1<<endl;
		}
    }
    return 0;
}
