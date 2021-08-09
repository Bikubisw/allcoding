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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int minSpeedOnTime(vector<int>& dist, double hour) {
	int finalans=-1;
     int i=1;
     int j=1e7;
     while(i<=j){
		 int mid=(i+j)/2;
		 //cout<<mid<<endl;
		 double ans=0.0;
		 for(int j=0;j<(int)dist.size();j++){
			 if(j!=(int)dist.size()-1){
				 ans+=ceil((double)(1.00)*dist[j]/mid);
				 //cout<<ans<<endl;
			 }
			 else{
				 ans+=((double)dist[j]/mid);
				 //cout<<ans<<endl;
			 }
		 }
		 if(ans<=hour){
			 finalans=mid;
			 j=mid-1;
		 }else{
			i=mid+1;
		 }
	 }
	 return finalans;
 }
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&it:arr){
		cin>>it;
	}
	double h;
	cin>>h;
	cout<<minSpeedOnTime(arr,h)<<endl;
    
    return 0;
}
