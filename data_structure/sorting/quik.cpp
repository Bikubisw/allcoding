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
int partition(vector<int>&arr,int start,int end){
	int i=start;
	int j=start;
	int pivot=arr[end];
	while(i<=end){
		if(arr[i]<=pivot){
			swap(arr[i],arr[j]);
			i++;
			j++;
		}else{
			i++;
		}
	}
	return j-1;
}
void quiksort(vector<int>&arr,int start,int end){
	if(start>=end){
		return;
	}
	int pindex=partition(arr,start,end);
	quiksort(arr,start,pindex-1);
	quiksort(arr,pindex+1,end);
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto &it:arr){
		cin>>it;
	}
	quiksort(arr,0,n-1);
	
    for(auto &it:arr){
		cout<<it<<" ";
	}
	cout<<endl;
    return 0;
}
