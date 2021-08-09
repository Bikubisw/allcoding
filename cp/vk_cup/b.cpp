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
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int h,w;
	cin>>h>>w;
	vector<vector<char>>arr(h,vector<char>(w,'0'));
	for(int i=0;i<w;i+=2){
		arr[0][i]='1';
	}
	for(int i=1;i<h-1;i++){
		for(int j=0;j<w;j++){
		if(j==0&&arr[i-1][j]!='1'&&arr[i-1][j+1]!='1'){
			arr[i][j]='1';
		}else if(j==w-1&&arr[i-1][j]!='1'&&arr[i-1][j-1]!='1'){
			arr[i][j]='1';
		}
	
	}
		
	}
	for(int i=0;i<w;i+=2){
		if(i==0&&arr[h-2][i]!='1'&&arr[h-2][i+1]!='1'){
			arr[h-1][i]='1';
		}
		else if(i==w-1&&arr[h-2][i]!='1'&&arr[h-2][i-1]!='1'){
			arr[h-1][i]='1';
		}else{
			if(arr[h-2][i]!='1'&&arr[h-2][i+1]!='1'&&arr[h-2][i-1]!='1'){
				arr[h-1][i]='1';
			}
			
		}
	}
	for(int i=0;i<h;i++){
	for(int j=0;j<w;j++){
		cout<<arr[i][j];
	}
	cout<<endl;
	}
	cout<<endl;
    }
    return 0;
}
