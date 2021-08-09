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
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>arr(n);
	for(auto &it:arr)cin>>it;
	vector<int> st;
	for(auto &it:arr){
		if((it&1)==0)st.push_back(it);
	}
	for(auto &it:arr){
		if(it&1)st.pb(it);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ans+=__gcd(st[i],2*st[j])>1;
		}
	}
	cout<<ans<<endl;
    }
    return 0;
}
