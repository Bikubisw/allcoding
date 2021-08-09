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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>val(n),wei(n);
    for(auto &it:val){
		cin>>it;
	}
	 for(auto &it:wei){
		cin>>it;
	}
	int cap;
	cin>>cap;
	vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cap;j++){
			dp[i][j]=dp[i-1][j];
			int a;
			dp[i][j]=max(dp[i][j],a=(j-wei[i-1]>=0)?dp[i-1][j-wei[i-1]]+val[i-1]:0);
		}
	}
	cout<<dp[n][cap]<<endl;
    return 0;
}
