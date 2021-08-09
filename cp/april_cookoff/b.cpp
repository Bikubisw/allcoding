#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<cfloat>
#include<unordered_set>
#include <unordered_map>
#include<string>
#include <cstring>
#include<stack>
#include<queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include<cassert>
#include<utility>
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main()
{
  
    int t;
    cin>>t;
    while(t--){
    	ll maxi=LLONG_MIN;
    	ll n,r;
    	cin>>n>>r;
    	vector<ll>a(n),b(n);
    	for(int i=0;i<n;i++){
    		cin>>a[i];
    	}
    	for(int i=0;i<n;i++){
    		cin>>b[i];
    	}
    	if(n==1){
    		cout<<b[0]<<endl;
    	}else{
    		for(int i=0;i<n-1;i++){
    			ll res=((a[i+1]-a[i])*r);
    			ll ans=b[i]-res+b[i+1];
    			maxi=max(ans,maxi);
    			
    		}
    		cout<<maxi<<endl;
    	}


    }



    return 0;
}