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
    IOS;
    int n;
	cin>>n;
	vector<int>arr(n);
	for(auto&it:arr)cin>>it;
	int maxi=INT_MIN;
	for(int i=0;i<n;i++){
		maxi=max(arr[i],maxi);
	}
	auto countsort=[&](int exp){
	vector<int>freq(10,0);
	for(int i=0;i<n;i++){
		freq[arr[i]/exp%10]++;
	}
	for(int i=1;i<10;i++){
		freq[i]=freq[i]+freq[i-1];
	}
	vector<int> result(n);
	for(int i=n-1;i>=0;i--){
		int pos=freq[arr[i]/exp%10]-1;
		result[pos]=arr[i];
		freq[arr[i]/exp%10]--;
	}
	for(int i=0;i<n;i++)arr[i]=result[i];
	};
	int exp=1;
	while(exp<=maxi){
		countsort(exp);
		exp*=10;
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
    return 0;
}
