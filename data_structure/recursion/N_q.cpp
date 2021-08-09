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
bool issafe(vector<vector<int>>&arr,int row,int col,int n){
	for(int i=row-1,j=col;i>=0;i--){
		if(arr[i][j]==1)return false;
	}
	for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
		if(arr[i][j]==1)return false;
	}
	for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
		if(arr[i][j]==1)return false;
	}
	return true;
}
void queen(vector<vector<int>>&arr,int n,int qsfar,int last){
		if(qsfar==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<(arr[i][j]==1?"q\t":"-\t");
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	
	for(int i=last+1;i<n*n;i++){
		int row=i/n;
		int col=i%n;
		if(arr[row][col]==0&&issafe(arr,row,col,n)){
		arr[row][col]=1;
		queen(arr,n,qsfar+1,row*n+col);
		arr[row][col]=0;
	}
	}
	
}
int main()
{
    IOS;
    int n;
    cin>>n;
    
    vector<vector<int>>arr(n,vector<int>(n,0));
    
    queen(arr,n,0,-1);

    return 0;
}
