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
	vector<int>arr(n);
	for(auto&it:arr)cin>>it;
	int ans=0;
	auto good=[](vector<int>&a)->bool{
		int n=a.size();
		if(n<=2){
			return true;
		}
		if(n>=5)return false;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if((a[i]>=a[j]&&a[j]>=a[k])||(a[i]<=a[j]&&a[j]<=a[k])){
					return false;
				}
			}
			}
		}
		return true;
	};
	for(int i=0;i<n;i++){
		vector<int>b;
		for(int j=i;j<n;j++){
			b.pb(arr[j]);
			if(good(b))ans++;
			else break;
		}
	}
	cout<<ans<<endl;

    }
    return 0;
}
