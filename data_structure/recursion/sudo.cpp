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
bool isval(vector<vector<int>>&arr,int row,int col,int n){
	for(int i=0,j=row;i<9;i++){
		if(arr[j][i]==n)return false;
	}
	for(int i=0,j=col;i<9;i++){
		if(arr[i][j]==n)return false;
	}
	
	int tr=(row/3)*3,tc=(col/3)*3;
	for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		if(arr[tr+i][tc+j]==n)return false;
		}	
	}
	return true;
}
void sudokusolver(vector<vector<int>>&arr,int i,int j){
	if(i==9){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		return;
	}
	int nr,nc;
	if(j==8){
		nc=0;
		nr=i+1;
	}
	else{
		nc=j+1;
		nr=i;
	}
	if(arr[i][j]!=0){
		sudokusolver(arr,nr,nc);
	}else{
	for(int n=1;n<=9;n++){
		if(isval(arr,i,j,n)){
			arr[i][j]=n;
			sudokusolver(arr,nr,nc);
			arr[i][j]=0;
		}
	}
}
	
}
int main()
{
    IOS;
    int n=9;
    vector<vector<int>>arr(n,vector<int>(n));
    for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
		}
    sudokusolver(arr,0,0);
    return 0;
}
