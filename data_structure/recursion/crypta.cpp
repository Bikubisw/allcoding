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
int getnum(string &s,unordered_map<char,int>&mp){
	ll ans=0;
	int pow=1;
	for(int i=s.length()-1;i>=0;i--){
		ans+=(mp[s[i]]*pow);
		pow*=10;
	}
	return (int)ans;
}
void solution(string &s1,string &s2,string &s3,string &uniq,vector<bool>&used,unordered_map<char,int>&mp,int idx){
	if(idx==(int)uniq.length()){
		int n1=getnum(s1,mp);
		int n2=getnum(s2,mp);
		int n3=getnum(s3,mp);
		if(n1+n2==n3){
		for(int i=0;i<26;i++){
			char ch='a'+i;
			if(mp.count(ch)){
				cout<<ch<<"-"<<mp[ch]<<" ";
			}
		}
		cout<<endl;
		}
		return;
	}
	for(int i=0;i<=9;i++){
		if(!used[i]){
			used[i]=true;
			mp[uniq[idx]]=i;
			solution(s1,s2,s3,uniq,used,mp,idx+1);
			used[i]=false;
			mp[uniq[idx]]=-1;
		}
	}
	
}
int main()
{
    IOS;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    unordered_map<char,int>mp;
    string unq="";
    for(char c:s1){
		if(mp.count(c)==0){
			unq+=c;
			mp[c]=-1;
		}
	}
	    for(char c:s2){
		if(mp.count(c)==0){
			unq+=c;
			mp[c]=-1;
		}
	}
	   for(char c:s3){
		if(mp.count(c)==0){
			unq+=c;
			mp[c]=-1;
		}
	}
	cout<<unq<<endl;
	vector<bool> used(10,false);
	solution(s1,s2,s3,unq,used,mp,0);
    return 0;
}
