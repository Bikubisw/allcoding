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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    IOS;
 	int k;
 	cin>>k;
 	vector<vector<int>>input;
 	for(int i=0;i<k;i++){
 		int a;
 		cin>>a;
 		vector<int>curr;
 		for(int i=0;i<a;i++){
 			int ele;
 			cin>>ele;
 			curr.push_back(ele);
 		}
 		input.push_back(curr);
 	}   
 	priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
 	for(int i=0;i<input.size();i++){
 		pq.push({input[i][0],{i,0}});
 	}
 	vector<int> ans;
 	while(!pq.empty()){
 		ppi curr=pq.top();
 		pq.pop();
 		ans.push_back(curr.first);
 		int i=curr.second.first;
 		int j=curr.second.second;
 		if(j+1<input[i].size()){
 			pq.push({input[i][j+1],{i,j+1}});
 		}
 	}
 	for(auto i:ans){
 		cout<<i<<" ";
 	}
    return 0;
}