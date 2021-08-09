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
void k_per(string st,int t,int c,string output,int ssf,int k){
	if(st.length()==0){
	if(ssf==k){
	cout<<output<<endl;
	}
	return;
	}
	k_per(st.substr(1),t,c+1,output+st[0],ssf+1,k);
	k_per(st.substr(1),t,c+1,output,ssf,k);
}
int main()
{
    IOS;
    string s;
    cin>>s;
    int n;
    cin>>n;
    map<char,int> mp;
    string st="";
    for(char c:s){
		if(mp.count(c)==0){
			st+=c;
		}
		mp[c]++;
	}
	k_per(st,st.length(),0,"",0,n);
	//cout<<st<<endl;
    return 0;
}
