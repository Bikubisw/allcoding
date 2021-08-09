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
bool haspath(vector<vector<Edges>> &graph,int n,int sv,int ev,vector<bool>&visited){
	visited[sv]=true;
	if(sv==ev)return true;

	for(int i=0;i<graph[sv].size();i++){
		int next=graph[sv][i].end;
		if(!visited[next]){
			if(haspath(graph,n,next,ev,visited)){
				return true;
			}
		}
	}
	return false;
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
    	graph[f].push_back(a);
    }
    int sv,ev;
    cin>>sv>>ev;
    vector<bool> visited(n,false);
    if(haspath(graph,n,sv,ev,visited)){
    	cout<<"true"<<endl;
    }else cout<<"false"<<endl;




    return 0;
}