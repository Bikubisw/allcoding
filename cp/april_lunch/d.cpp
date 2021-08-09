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
    IOS;
 	int t;
 	cin>>t;
 	while(t--){
 		int n,w,wr;
 		cin>>n>>w>>wr;
 		vector<int>arr(n);
 		unordered_map<int,int> mymap;
 		for(int i=0;i<n;i++){
 			cin>>arr[i];
 			mymap[arr[i]]++;
 		}
 		if(wr>=w){
 			cout<<"YES"<<endl;
 			continue;
 		}else{
 		ll ans=0;
 		ll finalans=0;
 		bool flag=false;
 		for(auto &it:mymap){
 			if(it.second>1){
 				if(it.second%2!=0){
 					it.second--;
 				}
 				ans+=(it.first*it.second);
 				finalans=ans+wr;
 				if(finalans>=w){
 					flag=true;
 					break;
 				}
 				finalans=0;
 			}

 		}
 		if(flag){
 			cout<<"YES"<<endl;
 		}else{
 			cout<<"NO"<<endl;
 		}
}
 	}

return 0;
}

