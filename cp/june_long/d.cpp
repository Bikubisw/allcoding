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
using namespace std;
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int n,m;
	cin>>n>>m;
	vector<int>city(n),dest(m);
	for(auto&it:city){
		cin>>it;
	}
	for(auto&it:dest){
		cin>>it;
	}
	vector<int>store(n);
	for(int i=0;i<n;i++){
		if(i==0){
			store[i]=0;
		}
		else if(city[i]!=0){
			store[i]=0;
		}else{
			
			store[i]=INT_MAX;
		}
	}
	int right=-1;
	for(int i=0;i<n;i++){
		if(city[i]==1)right=i;
		if(right!=-1){
			if(city[i]==0){
				store[i]=min(store[i],i-right);
			}
		}
		
	}
	int left=-1;
	for(int i=n-1;i>=0;i--){
		if(city[i]==2)left=i;
		if(left!=-1){
		if(city[i]==0){
			store[i]=min(store[i],left-i);
		}
		}
	}
	for(int i=0;i<m;i++){
		if(store[dest[i]-1]!=INT_MAX){
			cout<<store[dest[i]-1]<<" ";
		}else{
			cout<<-1<<" ";
		}
	}
	cout<<endl;
	
}
    return 0;
}
