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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	vector<vector<int>>dp(n,vector<int>(m));
	dp[0][0]=arr[0][0];
	for(int i=1;i<m;i++){
		dp[0][i]=arr[0][i]+dp[0][i-1];
	}
	for(int i=1;i<n;i++){
		dp[i][0]=dp[i-1][0]+arr[i][0];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			dp[i][j]=arr[i][j]+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n-1][m-1]<<endl;
	return 0;
}
