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
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	for(auto&it:a)cin>>it;
	for(auto&it:b)cin>>it;
	vector<int>diff(n);
	for(int i=0;i<n;i++){
		diff[i]=a[i]-b[i];
	}
	int sum=accumulate(all(diff),0);
	if(sum!=0){
		cout<<-1<<endl;
		continue;
	}
	vector<pi>neg,pos;
	for(int i=0;i<n;i++){
		if(diff[i]!=0&&diff[i]<0){
		neg.pb({i+1,diff[i]});
		}else if(diff[i]!=0&&diff[i]>0){
			pos.pb({i+1,diff[i]});
		}
	}
	vector<pi>ans;
	int i=0,j=0;
	int c=0;
	while(i<(int)neg.size()&&j<(int)pos.size()){
		ans.pb({pos[j].fi,neg[i].fi});
		c++;
		++neg[i].se;
		--pos[j].se;
		i+=neg[i].se==0;
		j+=pos[j].se==0;
		
	}
	cout<<c<<endl;
	for(int i=0;i<(int)ans.size();i++){
		cout<<ans[i].fi<<" "<<ans[i].se<<endl;
	}
    }
    return 0;
}
