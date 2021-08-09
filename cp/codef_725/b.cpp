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
	int n;
	cin>>n;
	vector<int>arr(n);
	for(auto&it:arr)cin>>it;
	
	ll sum=0;
	for(auto&it:arr){
	sum+=it;	
	}
	if(sum%n!=0){
		cout<<-1<<endl;
		continue;
	}
	int avg=sum/n;
	int ans=0;
	for(auto&it:arr){
		ans+=it>avg;
	}
	cout<<ans<<endl;
    }
    return 0;
}
