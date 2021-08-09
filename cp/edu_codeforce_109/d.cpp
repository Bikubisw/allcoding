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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<vector<ll>>store(5001,vector<ll>(5001,-1));
ll ans(int i,int j,vector<ll>&from,vector<ll>&to){
	if(i==(int)from.size()){return 0;}
	if(j==(int)to.size()) {return INT_MAX;}
	if(store[i][j]!=-1){return store[i][j];}
	ll small1=ans(i,j+1,from,to);
	ll small2=abs(from[i]-to[j])+ans(i+1,j+1,from,to);
	return store[i][j]=min(small1,small2);
	
}
int main()
{
    IOS;
    int t=1;
    while(t--){
	int n;
	cin>>n;
	vector<ll> from;
	vector<ll> to;
	for(int i=0;i<n;i++){
	int k;
	cin>>k;
	if(k==1){from.push_back(i);}
	else {to.push_back(i);}	
}
	//vector<vector<int>>store(5001,vector<int>(5001,-1));
	cout<<ans(0,0,from,to)<<endl;


	
    }
    return 0;
}


