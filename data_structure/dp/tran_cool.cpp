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
using namespace std;
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
int main()
{
    IOS;	
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&it:arr)cin>>it;
    int bst=-arr[0];
    int sst=0;
    int cst=0;
    for(int i=1;i<n;i++){
		int newbst=max(bst,cst-arr[i]);
		int newsst=max(sst,arr[i]+bst);
		int newcst=max(cst,sst);
		bst=newbst;
		sst=newsst;
		cst=newcst;
	}
	cout<<sst<<endl;
    return 0;
}
