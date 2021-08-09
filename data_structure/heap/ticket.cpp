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
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
int main()
{
    IOS;
 	int n;
 	cin>>n;
 	vector<int> arr(n);
 	queue<int> people;
 	priority_queue<int> pq;
 	for(int i=0;i<n;i++){
 		cin>>arr[i];
 		pq.push(arr[i]);
 		people.push(arr[i]);
 	}
 	int k;cin>>k;
 	int count=0;
 	while(!pq.empty()){
 		if(pq.top()==people.front()){
 			if(k==0){
 				count++;
 				cout<<count<<endl;
 				return 0;
 			}
 			else{
 				count++;
 				pq.pop();
 				people.pop();
 				k--;
 			}
 		}else{
 			people.push(people.front());
 			people.pop();
 			if(k==0){
 				k=people.size()-1;
 			}else{
 				k--;
 			}

 		}


 	}
 	cout<<count<<endl;
 	
    return 0;
}