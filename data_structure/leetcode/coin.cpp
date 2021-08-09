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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>coins(n);
    for(auto &it:coins){
		cin>>it;
	}
    int amount;
    cin>>amount;
    vector<int>dp(amount+1,-1);
	dp[0]=0;
	bool flag=true;
    for(int i=1;i<=amount;i++){
		for(int j=0;j<(int)coins.size();j++){
			if(i-coins[j]>=0&&flag==true){
				dp[i]=INT_MAX;
				dp[i]=min(dp[i],1+dp[i-coins[j]]);
				flag=false;
			}else if(i-coins[j]>=0&&flag==false){
				dp[i]=min(dp[i],1+dp[i-coins[j]]);
			}
		}
		
	}
	//for(int i=0;i<=amount;i++)cout<<dp[i]<<endl;
	cout<<dp[amount]<<endl;
    return 0;
}
