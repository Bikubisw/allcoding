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
#define MOD 1000000007
#define pb push_back
#define fi first
#define sf(n) scanf("%d",&n);
#define sfl(n) scanf("%ld",&n);
#define sfll(n) scanf("%lld",&n);
#define se second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
ll power(ll a,ll b){ll ans=1;while(b!=0){(b&1)?ans=(ans*a)%MOD:ans;a=(a*a)%MOD;b/=2;}return ans;}
void reverse(int i,int j,vector<int>&b){
	while(i<j){
		swap(b[i],b[j]);
		i++;
		j--;
	}
}
void rotatearray(vector<int>&b,int k){
	int n=(int)b.size();
	if(k==0)return;
	reverse(0,k-1,b);
	reverse(k,n-1,b);
	reverse(0,n-1,b);
}
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	for(auto&it:a)cin>>it;
	for(auto&it:b)cin>>it;
	int mini=INT_MAX;
	vector<int>st;
	for(int i=0;i<n;i++){
		int ans=(a[0]+b[i])%n;
		if(ans<=mini){
			mini=ans;
			st.pb(i);					
		}
	}
	//dbg(st.size());
	vector<int>small;
	rotatearray(b,st[0]);
	for(int i=0;i<n;i++){
		small.pb((a[i]+b[i])%n);
	}
	for(int i=1;i<(int)st.size();i++){
	rotatearray(b,st[i]);
	vector<int>ans;
	for(int j=0;j<n;j++){
		ans.pb((a[j]+b[j])%n);
	}
	for(int k=0;k<n;k++){
		if(small[k]==ans[k])continue;
		else if(small[k]<ans[k])break;
		else {
			for(int l=0;l<n;l++){
				small[l]=ans[l];
			}
		}
	}
	
	}
	for(int i=0;i<(int)small.size();i++){
		cout<<small[i]<<" ";
	}
	cout<<endl;
    }
    return 0;
}
