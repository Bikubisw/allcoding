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
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(NULL)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n,k;
	cin>>n>>k;
	vector<int>arr(n+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	ll ans=0;
	unordered_map<int,int> mp;
	for(int i=1;i<=k;i++){
		int j=i;
		int c=0;
		while(j<=n){
			mp[arr[j]]++;
			c++;
			j+=k;
		}
		int maxi=0;
		for(auto it:mp){
			maxi=max(it.second,maxi);
		}
		ans+=(c-maxi);
		mp.clear();
	}
	cout<<ans<<endl;
    }
    return 0;
}
