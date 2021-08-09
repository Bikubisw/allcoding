#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <cfloat>
#include <unordered_set>
#include <unordered_map>
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
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define dbg(x) cerr<<"["<<x<<"]"<<","<<endl;
#define dbg1(x,y) cerr<<"["<<x<<","<<y<<"]"<<","<<endl;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sf(n) scanf("%d",&n);
#define sfl(n) scanf("%ld",&n);
#define sfll(n) scanf("%lld",&n);
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
int count(int n,int m){
	if(n<0){
		return 0;
	}
	if(n==0)return 1;
	int c=0;
	for(int i=1;i<=m;i++){
		c+=count(n-i,m);
	}
	return c;
}
void print(int n,int m,string output){
	if(n<0){
		return ;
	}
	if(n==0){
	cout<<output<<endl;
	return ;
	}
	for(int i=1;i<=m;i++){
		print(n-i,m,output+to_string(i));
	}
}
vector<string> allpaths(int n,int m){
	
	if(n<0){
		vector<string>output;
		return output;
	}
	if(n==0){
		vector<string>output;
		output.pb("");
		return output;
	}
	vector<string>finaloutput;
	for(int i=1;i<=m;i++){
		vector<string>small=allpaths(n-i,m);
		for(auto it:small){
			finaloutput.pb(to_string(i)+it);
		}
	}
	return finaloutput;	
}
int main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    cout<<count(n,m)<<endl;
    vector<string> ans=allpaths(n,m);
    cout<<"[";
    for(int i=0;i<(int)ans.size();i++){
	if(i!=(int)ans.size()-1)cout<<ans[i]<<", ";
	else cout<<ans[i];
	}
	cout<<"]"<<endl;
	print(n,m,"");
    return 0;
}
