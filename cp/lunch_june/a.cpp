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
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
bool ispossible(vector<vector<char>>&arr,int k,int row,int col){
	int nrow=(row/k)*k,ncol=(col/k)*k;
	bool ans1=true,ans2=true;
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(arr[nrow+i][ncol+j]!='A'){
				ans1=false;
				break;
			}
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			if(arr[nrow+i][ncol+j]!='B'){
				ans2=false;
				break;
			}
		}
	}
	return ans1||ans2;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<char>>arr(n+1,vector<char>(m+1));
	bool ans=false;
	int l=0;
	while(l<n*m){
		int x,y;
		cin>>x>>y;
		if((l&1)==0){
			arr[x][y]='A';
		}else{
			arr[x][y]='B';
		}
		if(ispossible(arr,k,x,y)){
			ans=true;
			if((l&1)==0){cout<<"Alice"<<endl;}
			else{
				cout<<"Bob"<<endl;
			}
			break;
		}
		l++;
	}
	if(!ans)cout<<"Draw"<<endl;
    }
    return 0;
}
