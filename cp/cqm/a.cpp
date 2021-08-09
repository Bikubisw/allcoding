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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int maxi(int* arr,int n,vector<int>&ans){
	if(n==0){
		return 0;
	}
	if(ans[n]!=-1){
		return ans[n];
	}
	int leftans=arr[0]+maxi(arr+1,n-1,ans);
	int rightans=maxi(arr+1,n-1,ans);
	ans[n]=max(leftans,rightans);
	return ans[n];
}
int main()
{
    IOS;
	int n;
	cin>>n;
	int* input=new int[n];
	int c=0;
	for(int i=0;i<n;i++){
		cin>>input[i];
		if(input[i]<0)c++;
	}
	if(c==n){
		sort(input,input+n);
		cout<<input[n-1]<<endl;
	}
	else{
	vector<int> ans(n+1,-1);
	cout<<maxi(input,n,ans)<<endl;
}
	delete[] input;
	    return 0;
}
