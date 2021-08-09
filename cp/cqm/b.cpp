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
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    //IOS;
    int t;
    cin>>t;	
    while(t--){
	int n;
	cin>>n;
	vector<int> arr(n+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(arr[1]==1||arr[n]==n){
		cout<<1<<endl;
	}
	else if(arr[1]==n && arr[n]==1){
		cout<<3<<endl;
	}
	else{
		cout<<2<<endl;
	}
	
    }
    return 0;
}
