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
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define f first
#define s second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power_exp(ll a,ll b){
	ll ans=1;
	while(b>0){
		ll right=(b&1);
		if(right==1){
			ans=(ans*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;
	}
	return ans;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	int pow1=power_exp(2,n)-1;
	int ans1=power_exp(pow1,m);
	cout<<ans1<<endl;
    }
    return 0;
}
