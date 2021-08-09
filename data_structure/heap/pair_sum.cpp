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
 	int n;
 	cin>>n;
 	int*arr=new int[n];
 	unordered_map<int,int> mp;
 	for(int i=0;i<n;i++){
	cin>>arr[i];
	mp[arr[i]]++;
}
 	int ans=0;
 	for(int i=0;i<n;i++){
 		if(arr[i]==0){
 			int count=mp[arr[i]];
 			ans+=(count*(count-1))/2;
 			mp.erase(arr[i]);
 		}
 		else{
 		int compo=-arr[i];
 		 if(mp.find(compo)!=mp.end()){
 			//cout<<mp[arr[i]]<<" "<<mp[compo]<<endl;
 			ans+=(mp[arr[i]]*mp[compo]);
 			mp.erase(arr[i]);
 			mp.erase(compo);
 		}
 	}
 }
 	cout<<ans<<endl;
 	delete[] arr;
    return 0;
}