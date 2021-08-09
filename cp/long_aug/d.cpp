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
int  primeFactors (int num){
	int fc=0;
	int c=0;
	while(num%2==0){
		++c;
		num/=2;
	}
	if(c>0){
		++fc;
	}
	for(int i=3;i*i<=num;i+=2){
		int c=0;
		while(num%i==0){
			c++;
			num/=i;
		}
		if(c>0){
			++fc;
		}
	}
	if(num>2)++fc;
	return fc;
}
int cal(int k){
	ll ans=0;
	int pf=primeFactors(k);
	if(pf>1)ans+=pf;
	int l=k;
	for(int i=k-1;i>=2;i--){
		int rem=l%i;
		if(rem==0)break;
		if(i%rem==0)ans++;
	}
	return ++ans;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    vector<ll>dp(100001);
	dp[1]=0;
	dp[2]=1;
	dp[3]=3;
	dp[4]=6;
	for(int i=5;i<=100000;i++){
		dp[i]=dp[i-1]+cal(i);
	}
    while(t--){
	int n;
	cin>>n;
	cout<<dp[n]<<endl;
    }
    return 0;
}
