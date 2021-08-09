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
void k_per(string st,string output,int last,int n,int c,int k){
	if(c==k){
		cout<<output<<endl;
		return;
	}
	for(int i=last+1;i<n;i++){
		k_per(st,output+st[i],i,n,c+1,k);
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
    string st="";
    for(char c:s){
		if(mp.count(c)==0){
			st+=c;
		}
		mp[c]++;
	}
	k_per(st,"",-1,st.length(),0,n);
    return 0;
}
