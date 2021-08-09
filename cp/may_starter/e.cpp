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
#define pb push_back
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	vector<int>arr(m);
	unordered_map<int,int>mp;
	for(int i=0;i<m;i++){
		cin>>arr[i];
		mp[arr[i]]=i;
	}
	set<ll> s;
	for(auto i:mp){
		s.insert(i.second);
	}
	ll ans=m-*s.begin();
	for(ll i=0;i<m;i++){
		if(s.count(mp[arr[i]]))s.erase(mp[arr[i]]);
		if(!s.empty())ans=min(ans,i+1+(m-*s.begin()));
		else ans=min(ans,i+1);
	}
	cout<<ans<<endl;
	
    }
    return 0;
}
