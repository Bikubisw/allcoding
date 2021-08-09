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
void printDFShelper(vector<vector<Edges>>&edges,int n,int sv,vector<bool>&visited,vector<int>& output){
	output.push_back(sv);
	visited[sv]=true;
	for(int i=0;i<edges[sv].size();i++){
		int next=edges[sv][i].end;
		if(!visited[next]){
			printDFShelper(edges,n,next,visited,output);
		}

	}
}
vector<int> printDFS(vector<vector<Edges>>&edges,int n,int sv,vector<bool>&visited){
	vector<int>output;
	printDFShelper(edges,n,sv,visited,output);
	return output;
}
vector<vector<int>> allconnected_components(vector<vector<Edges>>&edges,int n){
	vector<bool> visited(n,false);
	vector<vector<int>> output;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			vector<int> smalloutput=printDFS(edges,n,i,visited);
			output.push_back(smalloutput);
		}
	}
	return output;
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
 	vector<vector<int>> output=allconnected_components(graph,n);
 	for(int i=0;i<output.size();i++){
 		for(int j=0;j<output[i].size();j++){
 			cout<<"["<<output[i][0]<<
 			cout<<to_string(output[i][j])<<" ,";
 		}
 		cout<<endl;
 	}



    return 0;
}