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
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;
    string s;
    cin>>s;
    int a=0,ab=0,abc=0;
    for(int i=0;i<(int)s.length();i++){
		if(s[i]=='a')a=2*a+1;
		else if(s[i]=='b')ab=2*ab+a;
		else if(s[i]=='c')abc=2*abc+ab;
	}
	cout<<abc<<endl;
    return 0;
}
