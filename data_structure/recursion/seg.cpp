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
    function<void (string,string,int)>seg=[&](string s,string ans,int count){
		if(s.length()==0){
			if(count!=0){
				ans+=to_string(count);
			}
			cout<<ans<<endl;
			return;
		}
		if(count==0){
		seg(s.substr(1),ans+s[0],0);
		}else{
			seg(s.substr(1),ans+to_string(count)+s[0],0);
		}
		seg(s.substr(1),ans,count+1);
			
	};
	seg(s,"",0);
    return 0;
}
