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
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
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
	vector<int>left(n),right(n),mid(n);
	left[0]=0;right[n-1]=0;
	for(int i=1;i<n;i++){
	left[i]=gcd(left[i-1],arr[i-1]);
	}
	for(int i=n-2;i>=0;i--){
	right[i]=gcd(right[i+1],arr[i+1]);
	}
	for(int i=0;i<n;i++){
		mid[i]=gcd(left[i],right[i]);
	}
	int maxi=*max_element(all(mid));
	vector<int>result;
	for(int i=0;i<n;i++){
		if(mid[i]==maxi){
			result.pb(i);
		}
	}
	int maxele=INT_MIN;
	if(result.size()==1){
		maxele=arr[result[0]];
	}else{
		for(int i=0;i<(int)result.size();i++){
			maxele=max(maxele,arr[result[i]]);
		}
	}
	ll sum=0;
	bool flag=false;
	for(int i=0;i<n;i++){
		if(arr[i]==maxele&&!flag){
			flag=true;
			continue;
		}
		sum+=(arr[i]/maxi);
	}
	cout<<++sum<<endl;
    }
    return 0;
}
