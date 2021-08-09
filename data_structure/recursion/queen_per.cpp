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
void queen(int n,int row,int col,string output,int num,vector<int>&arr){
	if(row==n){
		if(num==n){
			cout<<output<<endl;
		}
		return;
	}
	int nrow,ncol;
	string sep;
	if(col==n-1){
		nrow=row+1;
		ncol=0;
		sep="\n";
	}else{
		nrow=row;
		ncol=col+1;
		sep="\t";
	}
	for(int i=0;i<(int)arr.size();i++){
		if(arr[i]==0){
	arr[i]=1;
	queen(n,nrow,ncol,output+"q"+to_string(i+1)+sep,num+1,arr);
	arr[i]=0;
}
	
}
	queen(n,nrow,ncol,output+"-"+sep,num,arr);
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int> arr(n,0);
    queen(n,0,0,"",0,arr);
    return 0;
}
