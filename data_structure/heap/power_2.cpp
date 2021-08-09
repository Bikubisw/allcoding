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
int main()
{
    IOS;
    int t=1;
    while(t--){
	int n;
	cin>>n;
	vector<int> arr(n);
	vector<bool> visited(n,false);
	for(int i=0;i<n;i++){
	cin>>arr[i];
	if(arr[i]==1){visited[i]=true;}	
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(arr[i]==1){
			int leftans=INT_MAX;
			int rightans=INT_MAX;
			int lindex=i,rindex=i;
			for(int j=i-1;j>=0;j--){
				if(arr[j]==0&&!visited[j]){
					leftans=(int)(i-j);
					cout<<leftans<<endl;
					lindex=j;
				}
			}
			for(int k=i+1;k<n;k++){
				if(arr[k]==0&&!visited[k]){
					rightans=(int)(k-i);
					cout<<rightans<<endl;
					rindex=k;
				}
			}
			if(leftans<rightans){
				visited[lindex]=true;
				ans+=leftans;
			}else{
				visited[rindex]=true;
				ans+=rightans;
			}
		}
	}
	cout<<ans<<endl;
    }
    return 0;
}
