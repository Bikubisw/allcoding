#include<bits/stdc++.h>
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
class Person {
 
public:
    int weight;
 
    string s;
 
    // this is used to initialize the variables of the class
    Person(int weight,string s)
     {
     	this->weight=weight;
     	this->s=s;
     }
 };
bool compare(Person p1,Person p2){
	return p1.weight>p2.weight;
}
string maxpath;
int maximumpath=INT_MIN;
string minpath;
int minimumpath=INT_MAX;
string cpath;
int ceilvalue=INT_MAX;
string fpath;
int floorvalue=INT_MIN;
priority_queue<Person,vector<Person>,function<bool(Person,Person)>> pq(compare); 
void allpaths(vector<vector<Edges>>&graph,int n,int sv,int ev,vector<bool>&visited,string output,int wsfar,int &criteria,int &k){

	if(sv==ev){
		if(wsfar>maximumpath){
			maximumpath=wsfar;
			maxpath=output;
		}
		if(wsfar<minimumpath){
			minimumpath=wsfar;
			minpath=output;
		}
		if(wsfar>criteria){
			if(wsfar<ceilvalue){
				ceilvalue=wsfar;
				cpath=output;
			}
		}
		if(wsfar<criteria){
			if(wsfar>floorvalue){
				floorvalue=wsfar;
				fpath=output;
			}
		}
		if(pq.size()<k){
			Person p(wsfar,output);
			pq.push(p);
		}else{
			if(pq.top().weight<wsfar){
			pq.pop();
			Person p(wsfar,output);
			pq.push(p);
			}
		}
		return;
	}
	visited[sv]=true;
	for(int i=0;i<graph[sv].size();i++){
		int next=graph[sv][i].end;
		int wei=graph[sv][i].wei;
		if(!visited[next]){
			allpaths(graph,n,next,ev,visited,output+to_string(next),wsfar+wei,criteria,k);
		}
	}
	visited[sv]=false;	
}
int main()
{
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
 	int cri,k;
 	cin>>cri>>k;
 	vector<bool>visited(n,false);   
 	allpaths(graph,n,sv,ev,visited,to_string(sv),0,cri,k);
 	cout<<maxpath<<"@"<<maximumpath<<endl;
 	int min=INT_MAX;
 	string ans;
 	while(!pq.empty()){
 		cout<<pq.top().weight<<" "<<pq.top().s<<endl;
 		pq.pop();
 	}
    return 0;
}