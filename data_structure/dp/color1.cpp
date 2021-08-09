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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define pb push_back
#define endl '\n'
#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &it:arr){cin>>it;}
    function<int(vector<int>,int)> solve=[&](vector<int>arr,int n){
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=arr[i];
		}
		return sum;	
};
int ans=solve(arr,n);
cout<<ans<<endl;

	



    return 0;
}
