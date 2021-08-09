#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<cfloat>
#include<unordered_set>
#include <unordered_map>
#include<string>
#include <cstring>
#include<stack>
#include<queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include<cassert>
#include<utility>
#include<unordered_set>
#include<set>
#include<cmath>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
void callfuntion(vector<vector<int>>&arr,vector<vector<bool>>&visited,int i,int j,int row,int col){
	if(i<0||j<0||i==row||j==col||visited[i][j]||arr[i][j]==1){
		return;
	}

	visited[i][j]=true;
	for(int k=0;k<4;k++){
		callfuntion(arr,visited,i+x[k],j+y[k],row,col);
	}
	
}
int main()
{
    IOS;
 	int r,c;
 	cin>>r>>c;
 	vector<vector<int>>arr(r,vector<int>(c));
 	for(int i=0;i<r;i++){
 		for(int j=0;j<c;j++){cin>>arr[i][j];}
 	}   
 	vector<vector<bool>>visited(r,vector<bool>(c,false));
 	int count=0;
 	for(int i=0;i<r;i++){
 		for(int j=0;j<c;j++){
 			if(arr[i][j]==0&&!visited[i][j]){
 				callfuntion(arr,visited,i,j,r,c);
 				count++;
 			}
 		}
 	}
 	cout<<count<<endl;
    return 0;
}