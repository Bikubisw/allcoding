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
 	int n;
 	cin>>n;
 	vector<pair<int,int>>arr(n);
 	for(int i=0;i<n;i++){
 		cin>>arr[i].first>>arr[i].second;
 	}
 	bool ans=true;
 	for(int i=0;i<n-1;i++){
 		if(arr[i].first==arr[i+1].first||arr[i].second==arr[i+1].second){
 			continue;
 		}
 		ans=false;
 		break;
 	}
 	if(ans){
 		cout<<"YES"<<endl;
 	}else{
 		cout<<"NO"<<endl;
 	}
    return 0;
}