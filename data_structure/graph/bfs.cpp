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
	vector<bool> visited(n,false);
	queue<int>pendingnodes;
	pendingnodes.push(sv);
	visited[sv]=true;
	while(!pendingnodes.empty()){
		int front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front<<endl;
		for(int i=0;i<(int)edges[front].size();i++){
			int next=edges[front][i];
			if(!visited[next]){
				pendingnodes.push(next);
				visited[next]=true;
			}
		}
	}
	return 0;
}












