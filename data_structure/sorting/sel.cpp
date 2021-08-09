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
    for(int i=0;i<n-1;i++){
		int minindex=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minindex]){
				minindex=j;
			}
		}
		swap(arr[minindex],arr[i]);
	}
	for(auto &it:arr)cout<<it<<" ";
	cout<<endl;	
    return 0;
}
