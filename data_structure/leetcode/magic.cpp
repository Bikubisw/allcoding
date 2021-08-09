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
#include <numeric>
using namespace std;
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
 int largestMagicSquare(vector<vector<int>>& grid) {
       int n=grid.size(),m=grid[0].size();
       vector<vector<int>>rows(n+2,vector<int>(m+2)),cols(rows),d1(rows),d2(rows);
       for(int i=1;i<=n;i++){
		   for(int j=1;j<=m;j++){
			   rows[i][j]+=grid[i-1][j-1]+rows[i][j-1];
			   cols[i][j]+=grid[i-1][j-1]+cols[i-1][j];
			   d1[i][j]+=grid[i-1][j-1]+d1[i-1][j+1];
			   d2[i][j]+=grid[i-1][j-1]+d2[i-1][j-1];	
		   }
	   }
	   int res=0;
	   for(int i=1;i<=n;i++){
		   for(int j=1;j<=m;j++){
			   for(int k=min(n-i,m-j);k>res;k--){
				   int sum=d2[i+k][j+k]-d2[i-1][j-1];
				   bool match=sum==d1[i+k][j]-d1[i-1][j+k+1];
				   for(int l=0;l<=k&&match;l++){
					   match&=sum==rows[i+l][j+k]-rows[i+l][j-1];
					   match&=sum==cols[i+k][j+l]-cols[i-1][j+l];
				   }
				   res=match?k:res;
			   }
		   }
	   }
	  return res+1;
        
 }
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
	int ans=largestMagicSquare(arr);
	cout<<ans<<endl;
    return 0;
}
