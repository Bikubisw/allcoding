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
#include <cstdio>
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
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
void wordbreak(set<string>&st,string patt,string ans){
	if(patt.length()==0){
	cout<<ans<<endl;
	return;	
	}
	for(int i=0;i<(int)patt.length();i++){
		string left=patt.substr(0,i+1);
		if(st.count(left)==0){
			continue;
		}
		string right=patt.substr(i+1);
		wordbreak(st,right,ans+left+" ");
	}

}
int main()
{
    IOS;
    int n;
	cin>>n;
	set<string> st;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(st.count(s)==0)st.insert(s);
	}
	string patt;
	cin>>patt;
	wordbreak(st,patt,"");
	
    return 0;
}
