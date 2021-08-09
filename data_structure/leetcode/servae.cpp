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
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int,pair<int,int>> ppi;
typedef pair<int,int> pi;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

 vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
		using ll=long long;
	   int n=servers.size();
        int m=tasks.size();
        priority_queue<array<ll,2>, vector<array<ll,2>>, greater<array<ll,2>>> available;
        priority_queue<array<ll,3>, vector<array<ll,3>>, greater<array<ll,3>>> inUse;
        for(ll i=0; i<n; i++)
        {
            available.push({ll(servers[i]),i});
        }
        vector<int> ans;
        int i=0;
        for(;i<m;i++){
			
			while(!inUse.empty()&&inUse.top()[0]<=i){
				array<ll,3>a=inUse.top();
				inUse.pop();
				available.push({a[1],a[2]});
			}
			if(!available.empty()){
				array<ll,2> a=available.top();
				available.pop();
				ans.push_back(a[1]);
				inUse.push({i+tasks[i],a[0],a[1]});
			}else{
				array<ll,3> a=inUse.top();
				inUse.pop();
				ans.push_back(a[2]);
				a[0]+=tasks[i];
				inUse.push(a);
			}
		}
		
	   return ans;
	   
       
       
  }
int main()
{
    IOS;
    int n,m;
    cin>>n>>m;
    vector<int>servers(n),task(m);
    for(int i=0;i<n;i++)cin>>servers[i];
    for(int i=0;i<m;i++)cin>>task[i];
    vector<int> ans=assignTasks(servers,task);
    
    for(int i:ans)cout<<i<<endl;
    return 0;
}
