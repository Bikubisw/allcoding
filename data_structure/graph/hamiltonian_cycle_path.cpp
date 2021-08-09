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
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
class Edges
{
public:
	int start;
	int end;
	int wei;
	Edges(int st,int en,int weight){
		start=st;
		end=en;
		wei=weight;
	}
	
};
void allpaths(vector<vector<Edges>>&graph,int n,int sv,set<int>&visited,int origin,string psfar){
	if(visited.size()==n-1){
		bool flag=false;
		for(int i=0;i<graph[sv].size();i++){
			if(graph[sv][i].end==origin){
				flag=true;
				break;
			}
		}
		if(flag)cout<<psfar<<"*"<<endl;
		else cout<<psfar<<"."<<endl;
	}
	visited.insert(sv);
	for(int i=0;i<graph[sv].size();i++){
		int next=graph[sv][i].end;
		if(visited.count(next)==0){
			allpaths(graph,n,next,visited,origin,psfar+to_string(next));
		}
	}
	visited.erase(sv);
}
int main()
{
    IOS;
 	int n,e;
 	cin>>n>>e;
 	vector<vector<Edges>>graph(n);
 	for(int i=0;i<e;i++){
 		int f,s,wei;
 		cin>>f>>s>>wei;
 		Edges a(f,s,wei);
 		Edges b(s,f,wei);
 		graph[f].push_back(a);
 		graph[s].push_back(b);

 	}
 	int sv;
 	cin>>sv;
 	int orgin=sv;
 	set<int> visited;
 	allpaths(graph,n,sv,visited,orgin,to_string(sv));
    return 0;
}