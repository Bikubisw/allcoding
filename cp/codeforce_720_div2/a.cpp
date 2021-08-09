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
#include<unordered_set>
#include<set>
#include<cmath>
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
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
    	int a,b;
    	cin>>a>>b;
    	ll z=a*b;
    	ll x;
    	ll y;
    	bool flag=true;
    	while(z<=1e18&&flag){
    		for(ll i=a;i<=z;i+=a){
    			ll ans=(z-i);
    			if(ans%a==0){
    				x=i;
    				y=ans;
    				if(x+y==z&&x!=y&&(x>=1&&y>=1)){
    				flag=false;
    				break;
    			}
    			}
    		}
    		z+=(a*b);
    	}
    	if(!flag){
    		cout<<"YES"<<endl;
    		cout<<x<<" "<<y<<" "<<z-(a*b)<<endl;
    	}else cout<<"NO"<<endl;




    }
    return 0;
}