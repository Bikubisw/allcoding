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
    vector<vector<int>>arr(1001,vector<int>(1001));
    for(int i=1;i<=1000;i++){
		arr[i][1]=(i*(i+1))/2;
	}
	for(int i=1;i<=1000;i++){
		for(int j=2;j<=1000;j++){
			arr[i][j]=arr[i][j-1]+(i-1)+(j-1);
		}
	}	
    int t;
    cin>>t;
    while(t--){
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	ll ans=0;
	for(int i=x1;i<=x2;i++){
		ans+=arr[i][y1];
	}
	for(int i=y1+1;i<=y2;i++){
		ans+=arr[x2][i];
	}
	cout<<ans<<endl;
    }
    return 0;
}
