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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int &i:arr){
    	cin>>i;
    }
    int k;
    cin>>k;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
    	if(i<k){
    		pq.push(arr[i]);
    	}else{
    		if(pq.top()<arr[i]){
    			pq.pop();
    			pq.push(arr[i]);
    		}


    	}
    }

    int min=INT_MAX;
    while(!pq.empty()){
    	if(pq.top()<min){
    		min=pq.top();
    	}
    	pq.pop();
    }
    cout<<min<<endl;
    return 0;
}

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode*slow=head;
//         ListNode* fast=head;
//         while(fast!=NULL&&fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;
//             if(slow==fast)return true;
//         }
//         return false;
//     }
// };