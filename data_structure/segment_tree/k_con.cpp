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
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(auto &it:arr)cin>>it;
    auto kadnane=[&](vector<int> arr,int n){
	ll curr=0;
	ll maxi=NINF;
	for(int i=0;i<n;i++){
		curr+=arr[i];
		maxi=max(curr,maxi);
		if(curr<0){
			curr=0;
		}
	}
	return maxi;	
	};
	ll kadnanesum=kadnane(arr,n);
    if(k==1){
		cout<<kadnanesum<<endl;
		continue;
	}
	ll bestpresum=NINF;
	ll bestsuffsum=NINF;
	ll currpresum=0;
	ll currsuffsum=0;
	
	for(int i=0;i<n;i++){
		currpresum+=arr[i];
		bestpresum=max(currpresum,bestpresum);
	}
	ll totalsum=currpresum;
	for(int i=n-1;i>=0;i--){
		currsuffsum+=arr[i];
		bestsuffsum=max(currsuffsum,bestsuffsum);
	}
	ll ans=0;
	if(totalsum>=0){
		ans=max(bestpresum+bestsuffsum+((k-2)*totalsum),kadnanesum);
	}
	else{
		ans=max(kadnanesum,bestpresum+bestsuffsum);
	}
	cout<<ans<<endl;
}
    return 0;
}
