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
#define f first
#define s second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
void printpath(vector<vector<int>>&arr,int row,int col,string output,int i,int j,vector<vector<bool>>&visited){
	if(i>=row||j>=col||i<0||j<0||arr[i][j]==1||visited[i][j])return;
	if(i==row-1&&j==col-1){
		cout<<output<<endl;
		return;
	}
	visited[i][j]=true;
	printpath(arr,row,col,output+"t",i-1,j,visited);
	printpath(arr,row,col,output+"l",i,j-1,visited);
	printpath(arr,row,col,output+"d",i+1,j,visited);
	printpath(arr,row,col,output+"r",i,j+1,visited);
	visited[i][j]=false;
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
	vector<vector<bool>>visited(n,vector<bool>(m));
	printpath(arr,n,m,"",0,0,visited);
    return 0;
}
