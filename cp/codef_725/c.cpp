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
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
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
	int n,l,r;
	cin>>n>>l>>r;
	vector<int>arr(n);
	for(auto&it:arr)cin>>it;
	sort(all(arr));
	auto count_below=[&](int cutt)->ll{
		int i=0;
		int j=n-1;
		ll total=0;
		while(i<j){
			while(j>i&&arr[i]+arr[j]>cutt){
				j--;
			}
			total+=max(j-i,0);
			i++;
		}
		return total;
	};
	
	cout<<count_below(r)-count_below(l-1)<<endl;
    }
    return 0;
}
