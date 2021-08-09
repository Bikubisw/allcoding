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
#include <functional>
#include <numeric>
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define mod 998244353
#define pb push_back
#define fi first
#define sf(n) scanf("%d",&n);
#define sfl(n) scanf("%ld",&n);
#define sfll(n) scanf("%lld",&n);
#define se second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define dbg(x) cerr<<"["<<x<<"]"<<","<<endl;
#define dbg1(x,y) cerr<<"["<<x<<","<<y<<"]"<<","<<endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
    IOS;
    int t;
	cin>>t;
    while(t--){
	ll n;
	cin>>n;
	ll sum=0,ch=1,div=2,remi=n;
	auto lcm=[](ll a,ll b)->ll{
		ll ans=(a*b)/gcd(a,b);
		return ans;};
	while(remi>0){
		ll lc=lcm(ch,div);
		ll st=n/lc;
		dbg(lc,st);
		ll nrem=remi-st;
		sum=(sum%mod + (nrem*div)%mod)%mod;
		div++;
		ch=lc;
		remi=st;
	}
	//cout<<sum<<endl;
	
    }
    return 0;
}
