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
bool ispartite(vector<vector<int>>&edges,vector<int>&color,int sv){
	queue<int> pen;
	pen.push(sv);
	color[sv]=1;
	while(!pen.empty()){
		int front=pen.front();
		pen.pop();
		for(int i=0;i<(int)edges[front].size();i++){
				if(color[edges[front][i]]==-1){
					color[edges[front][i]]=1-color[front];
					pen.push(edges[front][i]);
				}else if(color[front]==color[edges[front][i]])return false;
		}
	}
	return true;
	/*if(color[sv]==-1)color[sv]=1;
	for(int i=0;i<(int)edges[sv].size();i++){
		int next=edges[sv][i];
		if(color[next]==-1){
			color[next]=1-color[sv];
			bool ans=ispartite(edges,color,next);
			if(!ans)return false;
		}
		else if(color[next]==color[sv])return false;
	}
	return true;*/
}
int main()
{
    IOS;
    int n,e;
    cin>>n>>e;
    vector<vector<int>>graph(n);
    for(int i=0;i<e;i++){
		int f,s,wei;
		cin>>f>>s>>wei;
		graph[f].push_back(s);
		graph[s].push_back(f);
	}
	bool flag=true;
	vector<int>color(n,-1);
	for(int i=0;i<n;i++){
		if(color[i]==-1){
			if(!ispartite(graph,color,i)){
				flag=false;
				break;
			}
		}
	}
	if(flag)cout<<"true"<<endl;
	else cout<<"false"<<endl;
    return 0;
}
