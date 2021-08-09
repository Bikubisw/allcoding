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
	int sc;
	int dest;
	int wei;
	Edges (int sc,int dest,int wei){
		this->sc=sc;
		this->dest=dest;
		this->wei=wei;
	}
};
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
    for(int i=0;i<n;i++){
    	for(int j=0;j<graph[i].size();j++){
    		cout<<graph[i][j].sc<<" "<<graph[i][j].dest<<" "<<graph[i][j].wei<<endl;
    	}
    }
    




    return 0;
}