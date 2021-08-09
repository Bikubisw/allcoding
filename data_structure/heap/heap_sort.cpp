#include<iostream>
#include<vector>
#include<map>
#include<climits>
#include<cfloat>
#include<unordered_set>
#include <unordered_map>
#include<string>
#include <cstring>
#include<stack>
#include<queue>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include<cassert>
#include<utility>
#include<unordered_set>
#include<set>
#include<cmath>
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
void heapsort(vector<int>&arr,int n){
	for(int i=1;i<n;i++){
		int childindex=i;
		while(childindex>0){
			int parentindex=(childindex-1)/2;
			if(arr[parentindex]>arr[childindex]){
				int temp=arr[parentindex];
				arr[parentindex]=arr[childindex];
				arr[childindex]=temp;
			}else{
				break;
			}
			childindex=parentindex;
		}
	}
	int size=n;
	while(size>1){
		int temp=arr[0];
		arr[0]=arr[size-1];
		arr[size-1]=temp;
		size--;
		int parentindex=0;
		int leftchidindex=2*parentindex+1;
		int rightchildindex=2*parentindex+2;
		while(leftchidindex<size){
			int minindex=parentindex;
			if(arr[leftchidindex]<arr[minindex]){
				minindex=leftchidindex;
			}if(arr[rightchildindex]<arr[parentindex]&&rightchildindex<size){
				minindex=rightchildindex;
			}
			if(minindex==parentindex)break;
			int tempo=arr[minindex];
			arr[minindex]=arr[parentindex];
			arr[parentindex]=tempo;
			parentindex=minindex;
			leftchidindex=2*parentindex+1;
			rightchildindex=2*parentindex+2;
		}
	}
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
 	heapsort(arr,n);
 	for(auto &it:arr){
 		cout<<it<<" ";
 	}
    return 0;
}