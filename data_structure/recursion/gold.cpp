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
int solution(int row,int col,vector<vector<bool>>&visited,vector<vector<int>>&arr,int n,int m){
	if(row<0||col<0||row>=n||col>=m||visited[row][col]||arr[row][col]==0){
		return 0;
	}
	visited[row][col]=true;
	int ans=arr[row][col];
	ans+=solution(row+1,col,visited,arr,n,m);
	ans+=solution(row,col+1,visited,arr,n,m);
	ans+=solution(row,col-1,visited,arr,n,m);
	ans+=solution(row-1,col,visited,arr,n,m);
	return ans;
}
int main()
{
    IOS;
	int n,m;
	cin>>n>>m;
	vector<vector<int>>arr(n,vector<int>(m));
	for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>arr[i][j];}}
	vector<vector<bool>>visited(n,vector<bool>(m,false));
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0&&!visited[i][j]){
				maxi=max(solution(i,j,visited,arr,n,m),maxi);
			}
		}
	}
	cout<<maxi<<endl;
    return 0;
}
