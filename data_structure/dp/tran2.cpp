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
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int n;
    cin>>n;
	vector<int>arr(n);
    for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	vector<int>dp1(n);
	dp1[0]=0;
	int mini=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]<mini){
			mini=arr[i];
		}
		dp1[i]=max(dp1[i-1],arr[i]-mini);
	}
	vector<int>dp(n);
	dp[n-1]=0;
	int maxi=arr[n-1];
	for(int i=n-2;i>=0;i--){
		if(arr[i]>maxi){
			maxi=arr[i];
		}
		dp[i]=max(dp[i+1],maxi-arr[i]);
	}
	int ans=INT_MIN;
	for(int i=0;i<n;i++){
	ans=max(ans,dp1[i]+dp[i]);
	}
	cout<<ans<<endl;
	
    return 0;
}
