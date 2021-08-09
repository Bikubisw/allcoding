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
struct node{
	int start;
	int end;
};
bool compare(node a,node b){
	return a.start<b.start;
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n,k,f;
	cin>>n>>k>>f;
	vector<node> time(n);
	for(int i=0;i<n;i++){
		cin>>time[i].start>>time[i].end;
	}
	sort(time.begin(),time.end(),compare);
	int ans=time[0].start;
	int maxi=time[0].end;
	for(int i=1;i<n;i++){
		ans+=max({0,time[i].start-maxi});
		maxi=max(maxi,time[i].end);
	}
	ans+=(f-maxi);
	cout<<(ans>=k?"YES\n":"NO\n");
}
    return 0;
}
