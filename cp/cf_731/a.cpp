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
#define MOD 1000000007
#define pb push_back
#define fi first
#define sf(n) scanf("%d",&n);
#define sfl(n) scanf("%ld",&n);
#define sfll(n) scanf("%lld",&n);
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
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	ll ans=0;
	if(x1==x2&&x2==x3&&x3==x1){
		int l=min(y1,y2);
		int r=max(y1,y2);
		if(y3>l&&y3<r){
		ans=abs(y1-y2);
		ans+=2;
		cout<<ans<<endl;
		}
		else{
		cout<<abs(y1-y2)<<endl;
		}
		continue;
	}
		if(y1==y2&&y2==y3&&y3==y1){
		int l=min(x1,x2);
		int r=max(x1,x2);
		if(x3>l&&x3<r){
		ans=abs(x1-x2);
		ans+=2;
		cout<<ans<<endl;
		}
		else{
		cout<<abs(x1-x2)<<endl;
		}
		continue;
		}
		ans=abs(x2-x1)+abs(y2-y1);
		cout<<ans<<endl;
    }
    return 0;
}
