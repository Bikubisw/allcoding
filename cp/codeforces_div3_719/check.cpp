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
 void moveZeroes(vector<int>& nums) {
        int i=0;
        int j=0;
        while(j<nums.size()){
        	if(nums[j]==1)j++;
        	else swap(nums[i++],nums[j++]);
        }
    }
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it:arr){
    	cin>>it;
    }

moveZeroes(arr);
for(auto &it:arr){
	cout<<it<<" ";
}
    




    return 0;
}