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
	vector<int>arr(n);
	for(auto &it:arr){
		cin>>it;
	}
	int tar;
	cin>>tar;
	vector<vector<bool>>dp(n+1,vector<bool>(tar+1));
	for(int i=0;i<=tar;i++){
		dp[0][i]=false;
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=tar;j++){
			dp[i][j]=dp[i-1][j];
			int c=(j-arr[i-1]>=0?dp[i-1][j-arr[i-1]]:false);
			dp[i][j]=dp[i][j]||c;
		}
	}
	cout<<(dp[n][tar]==true?"true":"false")<<endl;
    return 0;
}
