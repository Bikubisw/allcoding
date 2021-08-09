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
int main()
{
    IOS;
 	int n;
 	cin>>n;
 	vector<int>arr(n);
 	for(auto & it:arr){
 		cin>>it;
 	} 
 	int k;
 	cin>>k;
 	priority_queue<int, vector<int>,greater<int> > pq;
 	for(int i=0;i<k;i++){
 		pq.push(arr[i]);
 	}
 	for(int i=k;i<n;i++){
 		if(arr[i]>pq.top()){
 			pq.pop();
 			pq.push(arr[i]);
 		}
 	}
 	vector<int> ans;
 	while(!pq.empty()){
 		ans.push_back(pq.top());
 		pq.pop();
 	}
 	for(auto & it:ans){
 		cout<<it<<endl;
 	} 




    return 0;
}