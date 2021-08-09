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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
class PriorityQueue{
public:
	vector<int>pq;
	bool isempty(){
		return pq.size()==0;
	}
	int getmax(){
		return pq[0];
	}
	int getsize(){
		return pq.size();
	}
	void insert(int data){
		pq.push_back(data);
		int childindex=pq.size()-1;
		while(childindex>0){
			int parenindex=(childindex-1)/2;
			if(pq[parenindex]<pq[childindex]){
				int temp=pq[parenindex];
				pq[parenindex]=pq[childindex];
				pq[childindex]=temp;
			}else{
				break;
			}
			childindex=parenindex;
		}
	}
	int removemax(){
		if(pq.empty()){
			return INT_MAX;
		}
		int ans=pq[0];
		pq[0]=pq[pq.size()-1];
		pq.pop_back();
		int parenindex=0;
		int leftindex=2*parenindex+1;
		int rightindex=2*parenindex+2;
		while(leftindex<pq.size()){
			int maxindex=parenindex;
			if(pq[maxindex]<pq[leftindex]){
				maxindex=leftindex;
			}
			if(pq[maxindex]<pq[rightindex]&&rightindex<pq.size()){
				maxindex=rightindex;
			}
			if(maxindex==parenindex){break;}
			int temp=pq[maxindex];
			pq[maxindex]=pq[parenindex];
			pq[parenindex]=temp;
			parenindex=maxindex;
			leftindex=2*parenindex+1;
			rightindex=2*parenindex+2;
		}
		return ans;
	}



};
int main()
{
    IOS;
     PriorityQueue p;
    p.insert(20);
    p.insert(30);
    p.insert(10);
    p.insert(50);
    p.insert(40);
    p.insert(60);
    p.insert(90);
    p.insert(80);
    p.insert(70);
    cout<<p.getmax()<<endl;
    cout<<p.getsize()<<endl;
    while(!p.isempty()){
    	cout<<p.removemax()<<endl;
    }
    




    return 0;
}