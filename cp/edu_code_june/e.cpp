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
using ll=long long int;
using ull= unsigned long long int;
using ppi= pair<int,pair<int,int>>;
using pi= pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define MOD 1e9+7
#define pb push_back
#define f first
#define s second
#define INF 1e18
#define NINF -1e18
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
  int reductionOperations(vector<int>& nums) {
	priority_queue<int> pq;
	for(int i=0;i<nums.size();i++){
		pq.push(nums[i]);
	}
	int ans=0;
	vector<int>st;
	while(!pq.empty()){
		int lar=pq.top();
		st.push(lar);
		pq.pop();
		int slar=pq.top();
		pq.pop();
		st.push(slar);
		if(lar==slar){
			continue;
		}else{
			ans++;
			
		}
		
	}
        
  }
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(auto&it:arr)cin>>it;
    cout<<reductionOperations(arr)<<endl;
    
    return 0;
}
