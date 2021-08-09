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
#include<set>
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
 		int n,x;
 		cin>>n>>x;
 		vector<int>arr(n);
 		for(int i=0;i<n;i++)cin>>arr[i];
 		set<int> s;
 		for(auto &it:arr){
 			s.insert(it);
 		}
 		int len=s.size();
 		cout<<len<<endl;
 		return 0;
 		if(n-len>=x){
 			cout<<len<<endl;
 		}else cout<<n-x<<endl;


}

    return 0;
}