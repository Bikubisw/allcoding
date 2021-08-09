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
void solution(string s,string p,unordered_map<char,string> &mp,string &op){
	  if(p.length()==0){
		  if(s.length()==0){
		  set<char>st;
		  for(int i=0;i<(int)op.length();i++){
		  if(st.count(op[i])==0){
			  cout<<op[i]<<" -> "<<mp[op[i]]<<", ";
			    st.insert(op[i]);
		  }
		  }
		  cout<<"."<<endl;
	  }
	  return;
	  }
	if(mp.count(p[0])){
		string prev=mp[p[0]];
		if(s.length()>=prev.length()){
			string left=s.substr(0,prev.length());
			string right=s.substr(prev.length());
			if(left==prev){
			solution(right,p.substr(1),mp,op);
			}
		}
	}else{
	for(int i=0;i<(int)s.length();i++){
		string left=s.substr(0,i+1);
		string right=s.substr(i+1);
		mp[p[0]]=left;
		solution(right,p.substr(1),mp,op);
		mp.erase(p[0]);
	}	
	}
}
int main()
{
    IOS;
    string s,p;
    cin>>s>>p;
    unordered_map<char,string> mp;
    solution(s,p,mp,p);
    return 0;
}
