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
int first(vector<pi>&arr){
	sort(all(arr),[&](pi a,pi b)->bool{return a.first<b.fi;});
	return arr[0].second;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<vector<int>>arr(n,vector<int>(5));
	for(auto &it:arr)for(auto&i:it)cin>>i;
	int maxi=0;
	for(int i=1;i<n;i++){
		int total=0;
		for(int j=0;j<5;j++){
			total+=arr[i][j]<arr[maxi][j];
		}
		if(total>=3){
			maxi=i;
		}
	}
	for(int i=0;i<n;i++){
		int total=0;
		if(i==maxi)continue;
		for(int j=0;j<5;j++){
			total+=arr[i][j]<arr[maxi][j];
		}
		if(total>=3){
			maxi=-2;
			break;
		}
	}
	cout<<maxi+1<<endl;
}
	
    return 0;
}
