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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>val(n),wei(n);
    for(auto &it:val){
		cin>>it;
	}
	 for(auto &it:wei){
		cin>>it;
	}
	
	int cap;
	cin>>cap;
    vector<int> dp(cap+1,0);
    for(int i=1;i<=cap;i++){
		for(int j=0;j<n;j++){
			if(i-wei[j]>=0){
				dp[i]=max(dp[i],dp[i-wei[j]]+val[j]);
			}
		}
	}
	cout<<dp[cap]<<endl;
}
