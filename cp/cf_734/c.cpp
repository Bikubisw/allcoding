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
		int n,k;
		cin>>n>>k;
		vector<int>arr(n);
		map<int,vector<int>>mp;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			mp[arr[i]].pb(i);
		}
		vector<int> small;
		for(auto it:mp){
			if((int)it.second.size()>=k){
				int color=1;
				for(int i=0;i<(int)it.second.size();i++){
					if(i<k){
						arr[it.second[i]]=color;
					}else{
						arr[it.second[i]]=0;
					}
					color++;
				}
			}else{
				for(int i=0;i<(int)it.second.size();i++){
					small.pb(it.second[i]);
				}
			}
		}
		int c=0;
		int i;
		int z=small.size()%k;
		for(i=0;i<(int)small.size()-z;i++){
			arr[small[i]]=c+1;
			c++;
			c%=k;
		}
		while(i<(int)small.size()){
			arr[small[i]]=0;
			i++;
		}		
		for(auto it:arr)cout<<it<<" ";
		cout<<endl;
    }
    return 0;
}
