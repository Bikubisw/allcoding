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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
vector<int> getBiggestThree(vector<vector<int>>& grid){
	int n=(int)grid.size();
	int m=(int) grid[0].size();
	set<long long> s;
	for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		s.insert(grid[i][j]);
	}
	}
	auto check=[&](pair<int,int>a){
		return a.first>=0&&a.first<n&&a.second>=0&&a.second<m;
	};
	for(int l=1;l<=50;l++){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				pair<int,int>a=make_pair(i,j+l);
				pair<int,int>b=make_pair(i,j-l);
				pair<int,int>c=make_pair(i+l,j);
				pair<int,int>d=make_pair(i-l,j);
				if(!check(a)&&!check(b)&&!check(c)&&!check(d))goto end;
				if(check(a)&&check(b)&&check(c)&&check(d)){
					long long total=(long long)grid[i][j+l]+grid[i][j-l]+grid[i+l][j]+grid[i-l][j];
					for(int k=1;k<l;k++)total+=grid[i-k][j+l-k];
					for(int k=1;k<l;k++)total+=grid[i-k][j-l+k];
					for(int k=1;k<l;k++)total+=grid[i+k][j-l+k];
					for(int k=1;k<l;k++)total+=grid[i+k][j+l-k]				;
					s.insert(total);
				}
			}
		}
	}
		end:
			vector<int> ans;
			for(auto it:s)ans.push_back(it);
			if(ans.size()<=3){
				reverse(ans.begin(),ans.end());
				return ans;
			}
			vector<int> ok;
			for(int i=0;i<3;i++){
				ok.push_back(ans.back());
				ans.pop_back();
			}
			return ok;	
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
	vector<int> ans=getBiggestThree(arr);
	for(int i:ans)cout<<i<<endl;




    return 0;
}
