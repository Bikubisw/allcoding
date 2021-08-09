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
void k_len(set<char>st,string s,string output,int c,int k){
	if(c==k){
	cout<<output<<endl;
	return;
	}
	
	for(int i=0;i<(int)s.length();i++){
		if(st.count(s[i])==0){
			st.insert(s[i]);
			k_len(st,s,output+s[i],c+1,k);
			//auto it=st.find(s[i]);
			st.erase(s[i]);
		}
	}
}
int main()
{
    IOS;
    string s;
    cin>>s;
    int n;
    cin>>n;
    map<char,int> mp;
    string new_s="";
    for(char c:s){
		if(mp.count(c)==0){
			new_s+=c;
		}
		mp[c]++;
	}
	set<char>st;
	k_len(st,new_s,"",0,n);
	
    return 0;
}
