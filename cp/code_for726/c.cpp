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
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
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
	for(auto&it:arr){cin>>it;}
	sort(all(arr));
	int x=0,y=0;
	ll mindiff=INF;
	for(int i=1;i<n;i++){
		if(abs(arr[i]-arr[i-1])<mindiff){
		mindiff=abs(arr[i]-arr[i-1]);
			x=i-1;
			y=i;
		}
	}
	vector<int> ans(n);
	ans[0]=arr[x];
	ans[n-1]=arr[y];
	int m=1;
	for(int i=y+1;i<n;i++){
		ans[m++]=arr[i];
	}
	for(int i=0;i<x;i++){
		ans[m++]=arr[i];
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
    }
    return 0;
}
