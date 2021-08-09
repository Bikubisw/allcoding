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
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    string s;
    cin>>s;
    int n=s.length();
    s+=s;
    int ans1=0;
    int  ans2=0;
    int ans=INT_MAX;
    for(int i=0;i<(int)s.length();i++){
		if((i&1)==0&&s[i]=='0')ans1++;
		if((i&1)==1&&s[i]=='1')ans1++;
		if((i&1)==0&&s[i]=='1')ans2++;
		if((i&1)==1&&s[i]=='0')ans2++;
		if(i>=n){
		if(((i-n)&1)==0&&s[i-n]=='0')--ans1;
		if(((i-n)&1)==1&&s[i-n]=='1')--ans1;
		if(((i-n)&1)==0&&s[i-n]=='1')--ans2;
		if(((i-n)&1)==1&&s[i-n]=='0')--ans2;
		}
		if(i>=n-1){
		ans=min({ans,ans1,ans2});	
		}
	}
	cout<<ans<<endl;
    
    return 0;
}
