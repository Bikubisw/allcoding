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
ll cal(int n,int i,vector<int>&arr){
	if(i>n){
		return 0;
	}
	if(i==n)return 1;
	if(arr[i]!=-1){
		return arr[i];
	}
	ll ans1=cal(n,2*i,arr);
	ll  ans2=cal(n,2*i+1,arr);
	if(ans1==0&&ans2==0){
		arr[i]=0;
		return arr[i];
	}
	arr[i]=1+min(ans1,ans2);
	return arr[i];
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n+1,-1);
    ll ans=cal(n,1,arr);
    cout<<ans<<endl;
    return 0;
}
