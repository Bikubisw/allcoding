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
bool ispossible(vector<vector<int>>&board,int row,int col,int n){
	for(int i=row-1,j=col;i>=0;i--){
		if(board[i][j]==1)return false;
	}
	for(int i=row-1,j=col-1;i>=0&&4j>=0;i--,j--){
		if(board[i][j]==1)return false;
	}
	for(int i=row-1,j=col+1;i>=0&&col<n;i--,j++){
		if(board[i][j]==1)return false;
	}
	return true;
}
void nquuen(int n,vector<vector<int>>&board,int row){
	if(row==n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}	
	cout<<endl;
	return;
	}
	for(int i=0;i<n;i++){
		if(ispossible(board,row,i,n)){
			board[row][i]=1;
		nquuen(n,board,row+1);
		board[row][i]=0;
	}
	}
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    nquuen(n,board,0);
    return 0;
}
