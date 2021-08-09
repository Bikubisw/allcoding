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
#define f first
#define s second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
void total(vector<int>&arr,int n,int m,int k,int last){
	if(k>m){
		for(int i=0;i<n;i++){
			if(arr[i]!=0)cout<<"i";
			else cout<<"-";
		}
		cout<<endl;
		return;
	}
	for(int i=last+1;i<n;i++){
			arr[i]=k;
			total(arr,n,m,k+1,i);
			arr[i]=0;
	}
}
int main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    vector<int>arr(n,0);
    
	total(arr,n,m,1,-1);



    return 0;
}
