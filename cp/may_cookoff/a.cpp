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
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
	int D,d,a,b,c;
	cin>>D>>d>>a>>b>>c;
	ll total=(d*D);
	
	if(total>=42){
		cout<<c<<endl;
	}else if(total>=21&&total<42){
				cout<<b<<endl;

	}else if(total>=10&&total<21){
		cout<<a<<endl;
	}else{
		cout<<0<<endl;
	}
    }
    return 0;
}
