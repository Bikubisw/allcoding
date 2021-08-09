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
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int g,p;
	cin>>g>>p;
	vector<int>arr(11);
	for(int i=1;i<=10;i++){
		cin>>arr[i];
	}	
	ll total=0;
	int i=10;
	for(i=10;i>g;i--){
		total+=arr[i];
	}
	int mini =ceil((double)(total+1)/p);
	int maxi=ceil((double)(total+arr[i])/p);
	cout<<mini<<" "<<maxi<<endl;;
	
    }
    return 0;
}
