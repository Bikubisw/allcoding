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
	int k,n,m;
	cin>>k>>n>>m;
	vector<int>momo(n),poly(m);
	for(auto&it:momo)cin>>it;
	for(auto&it:poly)cin>>it;
	int i=0;
	int j=0;
	int curr=k;
	vector<int>ans;
	bool flag=true;
	while(i<n&&j<m){
		if(momo[i]==0){
			ans.pb(0);
			++curr;
			i++;
		}else if(poly[j]==0){
			ans.pb(0);
			j++;
			++curr;
		}
		else{
			if(momo[i]<=poly[j]){
				if(curr>=momo[i]){
					ans.pb(momo[i]);
					i++;
				}else{
					flag=false;
					break;
				}
			}
			else{
				if(curr>=poly[j]){
					ans.pb(poly[j]);
					j++;
				}else{
					flag=false;
					break;
				}
			}
		}
	}
	while(i<n){
			if(momo[i]==0){
			ans.pb(0);
			++curr;
			i++;
		}else{
		if(curr>=momo[i]){
		ans.pb(momo[i]);
		i++;
	}else{
		flag=false;
		break;
				}
		}
	}
	while(j<m){
		if(poly[j]==0){
			ans.pb(0);
			j++;
			++curr;
		}else{
			if(curr>=poly[j]){
					ans.pb(poly[j]);
					j++;
				}else{
					flag=false;
					break;
				}
		}
	}
	if(flag){
		for(auto it:ans){
			cout<<it<<" ";
		}
	}else{
		cout<<-1;
	}
	cout<<endl;
    }
    return 0;
}
