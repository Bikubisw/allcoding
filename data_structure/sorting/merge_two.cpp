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
    int n1,n2;
    cin>>n1;
    vector<int>arr1(n1);
    for(auto&it:arr1)cin>>it;
    cin>>n2;
    vector<int>arr2(n2);
    for(auto&it:arr2)cin>>it;
    vector<int>finali(n1+n2);
    int i=0;
    int j=0;
    int k=0;
    while(i<n1&&j<n2){
		if(arr1[i]<arr2[j]){
			finali[k++]=arr1[i++];
		}
		else{
			finali[k++]=arr2[j++];
		}
	}
	while(i<n1){
		finali[k++]=arr1[i++];
	}
	while(j<n2){
		finali[k++]=arr2[j++];
	}
	for(int i=0;i<n1+n2;i++){
		cout<<finali[i]<<endl;
	}
 return 0;
}
