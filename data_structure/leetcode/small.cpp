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
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
		cin>>nums[i];
	}
	map<int,int> freq;
	for(int i=0;i<(int)nums.size();i++){
		freq[nums[i]]++;
	}
	vector<int>ans;
	for(auto it:freq){
		ans.push_back(it.first);
	}
	reverse(ans.begin(),ans.end());
	ans.pop_back();
	int cnt=0;
	int total=0;
	for(int i:ans){
		cnt+=freq[i];
		total+=cnt;
	}
	return total;
    return 0;
}
