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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define INF 10000000
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it:arr){
		cin>>it;
	}
	vector<int>dp(n+1);
	dp[n]=0;
	for(int i=n-1;i>=0;i--){
		if(arr[i]==0){
			dp[i]=INF;
			continue;
		}
		int k=i+1;
		dp[i]=dp[k];
		for(int j=0;j<arr[i]&&k<=n;j++){
			dp[i]=min(dp[i],dp[k]);
			k++;
		}
		dp[i]++;
	}
cout<<dp[0]<<endl;
    return 0;
}
