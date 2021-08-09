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
int main()
{
    IOS;
 	int n;
 	cin>>n;
 	vector<int>arr(n);
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 	}
 	priority_queue<int,vector<int>,greater<int> > minheap;
 	priority_queue<int> maxheap;
 	for(int i=0;i<n;i++){
 		if(maxheap.size()&&arr[i]>maxheap.top()){
 			minheap.push(arr[i]);
 		}else {maxheap.push(arr[i]);
 		}

 	if(abs((int)maxheap.size()-(int)minheap.size())>1){
 		if(maxheap.size()>minheap.size()){
 			int temp=maxheap.top();
 			maxheap.pop();
 			minheap.push(temp);
 		}else{
 			int temp=minheap.top();
 			minheap.pop();
 			maxheap.push(temp);
 		}
 	}
 	int total=(int)maxheap.size()+(int)minheap.size();
 	int median;
 	if(total%2==1){
 		 if(maxheap.size()>minheap.size()){
 			 median=maxheap.top();
 		}else{
 		 median=minheap.top();
 		}
 	}else{
 		median=0;
 		if(!maxheap.empty())median+=maxheap.top();
 		if(!minheap.empty())median+=minheap.top();
 		median/=2;
 	}
 	cout<<median<<" ";

 	}   

    return 0;
}