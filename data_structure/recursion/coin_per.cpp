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
void permutation(int*arr,int n,set<int>&s,int tar,string output){
	if(tar<0){
		return;
	}
	if(tar==0){
		cout<<output+"."<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(s.count(arr[i])==0){
			s.insert(arr[i]);
			permutation(arr,n,s,tar-arr[i],output+to_string(arr[i])+"-");
			s.erase(arr[i]);
		}	
	}
}
int main()
{
    IOS;
    int n;
    scanf("%d",&n);
    int*arr=new int[n];
    for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int tar;
	scanf("%d",&tar);
	set<int> s;
	permutation(arr,n,s,tar,"");
	delete[] arr;
    return 0;
}
