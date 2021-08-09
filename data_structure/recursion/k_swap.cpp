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
int main()
{
    IOS;
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n=s.length();
    string max=s;
	function<void(string ,int)>k_swap=[&](string s,int k){
		if(k==0)return;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(s[i]<s[j]){
					swap(s[i],s[j]);t
					if(s.compare(max)>0){
						max=s;
					}
					k_swap(s,k-1);
					swap(s[i],s[j]);
				}
			}
		}
		
	};

	k_swap(s,k);
	cout<<max<<endl;
	
    return 0;
}
