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
	string s;
	cin>>s;ll ans=0;
	int arr[2]={-1,-1};
	for(int i=0;i<(int)s.length();i++){
		int c=s[i]-'0';
		if(c==1||c==0){
			arr[c^(i%2)]=i;
		}
		int mn=min(arr[0],arr[1]);
		cout<<i-mn<<endl;
		ans+=(i-mn);
	}
	cout<<ans<<endl;
    }
    return 0;
}
