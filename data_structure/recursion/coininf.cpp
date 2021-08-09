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
void print(int *arr,int n,int tar,string output){
	if(n==0){
		if(tar==0){
		cout<<output+"."<<endl;
		}
		return;
	}
	for(int i=(tar/arr[0]);i>=1;i--){
			string out="";
		for(int k=0;k<i;k++){
			out+=(to_string(arr[0])+"-");
		}
		print(arr+1,n-1,tar-(i*arr[0]),output+out);
	}
	print(arr+1,n-1,tar,output);
	
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
	print(arr,n,tar,"");
	delete[] arr;
    return 0;
}
