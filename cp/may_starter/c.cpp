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
    int t;
    cin>>t;
    unordered_map<int,int> mp;
    while(t--){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		mp[a]++;
	}
	vector<int> res;
	for(auto it:mp){
		if(it.first>=1&&it.first<=n){
			if(it.second>1){
				res.push_back(it.first);
			}
		}
	}
	cout<<res.size()<<" ";
	sort(res.begin(),res.end());
	for(int i:res){
		cout<<i<<" ";
	}
	cout<<endl;
	mp.clear();
    }
    return 0;
}
