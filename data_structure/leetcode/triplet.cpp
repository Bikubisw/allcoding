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
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(auto &it:nums){
		cin>>it;
	}
	vector<vector<int>>ans;
	sort(nums.begin(),nums.end());
	for(int i=0;i<(int)nums.size();i++){
		if(i!=0&& nums[i-1]==nums[i]){
			
			continue;
		}
		int search=0-nums[i];
		int l=i+1;
		int r=nums.size()-1;
		while(l<r){
			if(nums[l]+nums[r]==search){
				vector<int> small;
				small.push_back(nums[i]);
				small.push_back(nums[l]);
				small.push_back(nums[r]);
				ans.push_back(small);
				while(l<r&&nums[l]==nums[l+1])l++;
				while(l<r&&nums[r]==nums[r-1])r--;
				l++;
				r--;
			}
			else if(nums[l]+nums[r]>search){
				r--;
			}
			else{
				l++;
			}
		}	
	}
	for(int i=0;i<(int)ans.size();i++){
		for(int j=0;j<(int)ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
	cout<<endl;
	}
    
return 0;
}
