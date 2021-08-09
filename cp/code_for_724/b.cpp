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
#include <array>
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
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
		int n;
		string s;
		cin>>n>>s;
		auto solve=[&](string &s)->string{
		vector<string> strings={""};
		while(true){
			vector<string>nstrings;
			for(auto &str:strings){
			for(int i=0;i<26;i++){
				string nstr=str+char('a'+i);
				nstrings.pb(nstr);
				if(s.find(nstr)==string::npos){
					return nstr;
				}
			}
			
		}
		strings=nstrings;
		}
			
		};
		cout<<solve(s)<<endl;
	}
	return 0;
}
