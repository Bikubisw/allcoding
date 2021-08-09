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
	for(int i=0;i<n;++i){
		dp[i][m-1]=arr[i][m-1];
	}
	for(int i=m-2;i>=0;--i){
		for(int j=0;j<n;++j){
			if(j==0){
			dp[j][i]=arr[j][i]+max(dp[j+1][i+1],dp[j][i+1]);	
			}
			else if(j==n-1){
				dp[j][i]=arr[j][i]+max(dp[j-1][i+1],dp[j][i+1]);
			}
		else{
			dp[j][i]=arr[j][i]+max(dp[j+1][i+1],max(dp[j][i+1],dp[j-1][i+1]));
		}
	}
	}
	int maxi=dp[0][0];
	for(int i=0;i<n;i++){
		maxi=max(maxi,dp[i][0]);
	}
	cout<<maxi<<endl;
	


    return 0;
}
