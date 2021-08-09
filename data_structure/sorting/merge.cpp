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
void merge(int*arr,int start,int end){
	int size=end-start+1;
	int *output=new int[size];
	int mid=(start+end)>>1;
	int i=start;
	int j=mid+1;
	int k=0;
	while(i<=mid&&j<=end){
		if(arr[i]<arr[j]){
			output[k++]=arr[i++];
		}else{
			output[k++]=arr[j++];
		}
	}
	while(i<=mid){
		output[k++]=arr[i++];
	}
	while(j<=end){
		output[k++]=arr[j++];
	}
	int m=0;
	for(int i=start;i<=end;i++){
		arr[i]=output[m++];
	}
	delete[] output;
}
void mergesort(int *arr,int start,int end){
	if(start>=end){
		return;
	}
	int mid=(start+end)>>1;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,end);
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
	mergesort(arr,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
    delete[]arr;
    return 0;
}
