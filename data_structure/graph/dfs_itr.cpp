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
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges(n);
    for(int i=0;i<e;i++){
		int f,s,wei;
		cin>>f>>s>>wei;
		edges[f].push_back(s);
		edges[s].push_back(f);
	}
	int sv;
	cin>>sv;
	vector<bool>visited(n,false);
	stack<pair<int,string>> st;
	st.push({sv,""+to_string(sv)});
    while(!st.empty()){
		pair<int,string> front=st.top();
		st.pop();
		if(visited[front.first]==false){
			visited[front.first]=true;
			cout<<front.first<<"@"<<front.second<<endl;
			for(int i=0;i<(int)edges[front.first].size();i++){
				int n=edges[front.first][i];
				if(visited[n]==false){
					st.push({n,front.second+to_string(n)});
				}
			}
		}
	}




    return 0;
}
