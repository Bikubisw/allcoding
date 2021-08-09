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
void k_len(string s,vector<char>&arr,int ssf,int k){
	if(s.length()==0){
		if(ssf==k){
		for(int i=0;i<(int)arr.size();i++){
			cout<<arr[i];
		}
		cout<<endl;
		}
		return;
	}
	
	for(int i=0;i<(int)arr.size();i++){
		if(arr[i]=='\0'){
			arr[i]=s[0];
			k_len(s.substr(1),arr,ssf+1,k);
			arr[i]='\0';
		}
	}
	k_len(s.substr(1),arr,ssf,k);
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
	vector<char>arr(n,'\0');
	k_len(st,arr,0,n);
    return 0;
}
