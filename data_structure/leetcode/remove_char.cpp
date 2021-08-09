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
bool isexists(string s,string p){
	int j=0;
	for(int i=0;i<(int)s.length()&&j<(int)p.length();i++){
		j+=s[i]==p[j];
	}
	return j==(int)p.length();
}
int maximumRemovals(string s, string p, vector<int>& removable) {
       int left=0;
       int right=removable.size()-1;
       int k=-1;
       while(left<=right){
		   int mid=(left+right)/2;
		   string st=s;
		   for(int i=0;i<=mid;i++){
			   st[removable[i]]='?';
		   }
		   if(isexists(st,p)){
			   k=mid;
			   left=mid+1;
		   }else{
			   right=mid-1;
		   }
	   }
	   if(k==-1){
		   return 0;
	   }
	   return ++k;
}
int main()
{
    IOS;
    string s,p;
    cin>>s>>p;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&it:arr)cin>>it;
    int mini=maximumRemovals(s,p,arr);
	cout<<mini<<endl;
    return 0;
}
