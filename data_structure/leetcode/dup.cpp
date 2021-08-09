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
 int removeElement(vector<int>& nums, int val) {

        for(int i=0;i<nums.size();i++){
        if(nums[i]==val){
            for(int j=i;j<nums.size()-1;j++){
                nums[j]=nums[j+1];
            }
            nums.pop_back();
            i--;
        }
        }
        return nums.size();
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
    int val;
    cin>>val;

cout<<removeElement(arr,val)<<endl;
for(auto &it:arr){
    	cout<<it<<endl;
    }


    return 0;
}