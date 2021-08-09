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
class Edges{
public:
	int st;
	int end;
	int wei;
	Edges(int st,int end,int wei){
		this->st=st;
		this->end=end;
		this->wei=wei;
	}
};
void allpaths(vector<vector<Edges>>&graph,int n,int sv,int ev,vector<bool>&visited,string output,int wsfar){
	if(sv==ev){
		cout<<output<<"@"<<wsfar<<endl;
		return;
	}
	visited[sv]=true;
	for(int i=0;i<graph[sv].size();i++){
		int next=graph[sv][i].end;
		int wei=graph[sv][i].wei;
		if(!visited[next]){
			allpaths(graph,n,next,ev,visited,output+to_string(next),wsfar+wei);
		}
	}
	visited[sv]=false;	
}
int main()
{
    IOS;
 	int n,e;
 	cin>>n>>e;
 	vector<vector<Edges>> graph(n);
    for(int i=0;i<e;i++){
    	int f,s,wei;
    	cin>>f>>s>>wei;
    	Edges a(f,s,wei);
    	Edges b(s,f,wei);
    	graph[f].push_back(a);
    	graph[s].push_back(b);
    }
 	int sv,ev;
 	cin>>sv;
 	cin>>ev;
 	vector<bool>visited(n,false);   
 	allpaths(graph,n,sv,ev,visited,to_string(sv),0);
    return 0;
}