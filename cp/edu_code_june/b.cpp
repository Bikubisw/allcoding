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
	int n;
	cin>>n;
	vector<int> arr(n);
	for(auto &it:arr){
		cin>>it;
	}
	vector<int>even,odd;
	for(int i=0;i<n;i++){
		if(arr[i]&1){
		odd.push_back(arr[i]);
		}else{
			even.push_back(arr[i]);
		}
	}
	int k=0;
	for(int i=0;i<(int)even.size();i++){
		arr[k]=even[i];
		k++;
	}
	for(int i=0;i<(int)odd.size();i++){
		arr[k++]=odd[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		int gcd=__gcd(arr[i],2*arr[j]);
		if(gcd>1)ans++;
	}	
	}
	cout<<ans<<endl;
    }
    return 0;
}
