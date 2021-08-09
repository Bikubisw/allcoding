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
const int maxi=100001;
long makeshaffola(int i){
	string s=to_string(i);
	string p=s;
	p.pop_back();
	reverse(all(p));
	s+=p;
	long ans=0;
	long pow=1;
	for(int i=s.length()-1;i>=0;i--){
		ans+=(s[i]-'0')*pow;
		pow*=10;
	}
	return ans;
}
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
int main()
{
    IOS;
    vector<ll>shaffola(maxi);
    shaffola[0]=-1;
    for(int i=1;i<=maxi;i++){
		if(i<10){
		shaffola[i]=(ll)i;
	}else{
		shaffola[i]=makeshaffola(i);
	}
	}
	vector<ll>prefix(maxi);
	prefix[0]=0;
	for(int i=1;i<=maxi;i++){
		prefix[i]=prefix[i-1]+(ll)shaffola[i];
	}
    int t;
    cin>>t;
    while(t--){
	int l,r;
	cin>>l>>r;
	ll sum=prefix[r]-prefix[l];
	ll ans=power(shaffola[l],sum);
	cout<<ans<<endl;
    }
    return 0;
}
