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
#include <iomanip>
#include <functional>
#include <numeric>
using namespace std;
using ll=long long int ;
using ull= unsigned long long int ;
using ppi= pair<int,pair<int,int>> ;
using pi= pair<int,int> ;
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define pb push_back
#define fi first
#define se second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
void nqueen(int n,vector<bool>&nd,vector<bool>&rd,vector<bool>&col,string ans,int row){
	if(row==n){
		cout<<ans+"."<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		int normaldia=row-i+n-1;
		int regulardia=row+i;
		if(!col[i]&&!nd[normaldia]&&!rd[regulardia]){
			col[i]=true;
			nd[normaldia]=true;
			rd[regulardia]=true;
			nqueen(n,nd,rd,col,ans+to_string(row)+"-"+to_string(i)+", ",row+1);
			col[i]=false;
			nd[normaldia]=false;
			rd[regulardia]=false;
		}
	}
}
int main()
{
    IOS;
    int n;
    cin>>n;
    vector<bool>nd(2*n-1,false);
    vector<bool>rd(2*n-1,false);
    vector<bool>cols(n,false);
    nqueen(n,nd,rd,cols,"",0);
    return 0;
}
