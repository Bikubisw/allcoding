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
#include <numeric>
using namespace std;
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int minsum=INT_MAX;
string ans="";
void tug(vector<int>&arr,vector<int>&set1,vector<int>&set2,int index,int set1sum,int set2sum){
	if(index==(int)arr.size()){
		int delta=abs(set1sum-set2sum);
		if(delta<minsum){
			ans="";
			minsum=delta;
			ans+="[";
			for(int i=0;i<(int)set1.size();i++){
			if(i==set1.size()-1)ans+=to_string(set1[i]);
			else ans+=to_string(set1[i])+", ";
			}
			ans+="]";
			ans+=" ";
			ans+="[";
			for(int i=0;i<(int)set2.size();i++){
			if(i==set2.size()-1)ans+=to_string(set2[i]);
			else ans+=to_string(set2[i])+", ";
			}
			ans+="]";
		}
		
		return;
	}
	if(set1.size()<((arr.size()+1)/2)){
	set1.pb(arr[index]);
	tug(arr,set1,set2,index+1,set1sum+arr[index],set2sum);
	set1.pop_back();
}
	if(set2.size()<((arr.size()+1)/2)){
	set2.pb(arr[index]);
	tug(arr,set1,set2,index+1,set1sum,set2sum+arr[index]);
	set2.pop_back();
}
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&it:arr)cin>>it;
    vector<int>set1,set2;
  
	tug(arr,set1,set2,0,0,0);

	cout<<ans<<endl;

    return 0;
}
