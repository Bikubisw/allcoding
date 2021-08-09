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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int mike=0;
void callfunction(vector<vector<int>>&arr,int i,int j,int n,int m){
	if(i==n||j==m||i<0||j<0){
		return;
	}
	if(i+1<=n-1){
	if(arr[i+1][j]==1){
		mike++;
			arr[i+1][j]=0;
		callfunction(arr,i+1,j,n,m);
	}
}
if(j+1<=m-1){
	if(arr[i][j+1]==1){
		mike++;
			arr[i][j+1]=0;
		callfunction(arr,i,j+1,n,m);
	}}
	if(i-1>=0){
	if(arr[i-1][j]==1){
		mike++;
		arr[i-1][j]=0;

		callfunction(arr,i-1,j,n,m);
	}
}
if(j-1>=0){
	if(arr[i][j-1]==1){
		mike++;
				arr[i][j-1]=0;

		callfunction(arr,i,j-1,n,m);
	}
}

}
int main()
{
    IOS;
 	int t;
 	cin>>t;
 	while(t--){
 		int n,m;
 		cin>>n>>m;
 		vector<vector<int>>arr(n,vector<int>(m));
 		for(int i=0;i<n;i++){
 			string s;
 			cin>>s;
 			for(int j=0;j<s.length();j++){
 				arr[i][j]=s[j]-'0';
 			}
 		}
 		int mike=0;
 		int terms=0;
 		int finalans=0;
 		for(int i=0;i<n;i++){
 			for(int j=0;j<m;j++){
 				if(arr[i][j]==1){
 					arr[i][j]=0;
 					callfunction(arr,i,j,n,m);
 					if(terms%2!=0){
 						finalans+=mike;
 					}
 					terms++;
 					mike=0;
 				}
 			}
 		}
 		cout<<finalans<<endl;
 	}   




    return 0;
}