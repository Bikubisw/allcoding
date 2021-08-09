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
struct Node{
	int v;
	string psf;
	int wsf;
};
class compatartor{
	public:
	int operator()(const Node&a,const Node&b ){
			return a.wsf>=b.wsf;
	}
	
};
class Edges{
	public:
	int st;
	int end;
	int wei;
	Edges(int f,int s,int w){
		this->st=f;
		this->end=s;
		this->wei=w;
	}
};
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
	vector<bool> visited(n,false);
	priority_queue<Node,vector<Node>,compatartor> pq;
	Node a;
	a.v=sv;
	a.psf=to_string(sv);
	a.wsf=0;
	pq.push(a);
	while(!pq.empty())
	{
		Node front=pq.top();
		pq.pop();
		if(!visited[front.v]){
			visited[front.v]=true;
			cout<<front.v<<" via"<<front.psf<<"@"<<front.wsf<<endl;
			for(int i=0;i<(int)graph[front.v].size();i++){
				if(!visited[graph[front.v][i].end]){
					Node a;
					a.v=graph[front.v][i].end;
					a.psf=front.psf+to_string(graph[front.v][i].end);
					a.wsf=front.wsf+graph[front.v][i].wei;
					pq.push(a);
				}
			}
		}
		
		
	}
    
    




    return 0;
}
