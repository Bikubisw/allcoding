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
    IOS;
    int t;
    cin>>t;
    while(t--){
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n;i++){
		if((i+1)<n&&(i+3)<n&&(i+2)<n&&(s[i]<s[i+2]||s[i+1]<s[i+3])){
			if(s[i]<s[i+2])swap(s[i],s[i+2]);
			else if(s[i+1]<s[i+3])swap(s[i+1],s[i+3]);
			break;
		}
	}

	cout<<s<<endl;


    }
    return 0;
}
