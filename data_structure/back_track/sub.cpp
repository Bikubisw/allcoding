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
void subset(int *arr,int n,int tar,string output){
	if(tar<0)return;
	
	if(n==0){
		if(tar==0){
			cout<<output<<endl;
		}
		return;
	}
	subset(arr+1,n-1,tar-arr[0],output+to_string(arr[0])+",");
	subset(arr+1,n-1,tar,output);
}
int main()
{
    IOS;
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int tar;
	cin>>tar;
	subset(arr,n,tar,"");
	delete[] arr;




    return 0;
}
