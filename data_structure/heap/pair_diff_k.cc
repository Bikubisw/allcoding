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
 	vector<int> arr(n);
 	unordered_map<int,int> mymap;
 	int k;
 	cin>>k;
 	int ans=0;
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 		int compo=arr[i]+k;
 		ans+=mymap[compo];
 		if(k!=0){
 			compo=arr[i]-k;
 			ans+=mymap[compo];
 		}
 		mymap[arr[i]]++;
 	}   
 	cout<<ans<<endl;
    return 0;
}