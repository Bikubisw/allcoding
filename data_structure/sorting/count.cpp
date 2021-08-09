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
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    //IOS;
	int n;
	cin>>n;
	vector<int>arr(n);
	for(auto&it:arr){cin>>it;}
	int maxi=INT_MIN,mini=INT_MAX;
	for(int i=0;i<n;i++){
		maxi=max(arr[i],maxi);
		mini=min(mini,arr[i]);
	}	
	int unique=maxi-mini+1;
	vector<int>freq(unique,0);
	for(int i=0;i<n;i++){
		freq[arr[i]-mini]++;
	}
	for(int i=1;i<unique;i++){
		freq[i]=freq[i]+freq[i-1];
	}
	vector<int> result(n);
	for(int i=n-1;i>=0;i--){
		int pos=freq[arr[i]-mini]-1;
		result[pos]=arr[i];
		freq[arr[i]-mini]--;
	}
	for(int i=0;i<n;i++){
		cout<<result[i]<<endl;
	}
    return 0;
}
