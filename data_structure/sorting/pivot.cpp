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
    int pivot;
    cin>>pivot;
    int count=0;
    int initialpivotindex=-1;
    for(int i=0;i<n;i++){
		if(arr[i]<pivot){
			count++;
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i]==pivot){
			initialpivotindex=i;
			break;
		}
	}
	int i=0,j=n-1;
	int pindex=count;
	swap(arr[initialpivotindex],arr[count]);
	while(i<pindex&&j>pindex){
		if(arr[i]<pivot){
		i++;
		}
		else if(arr[j]>pivot){
			j--;
		}
		else{
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	
    for(auto&it:arr)cout<<it<<" ";
	cout<<'\n';



    return 0;
}
