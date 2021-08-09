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
#define f first
#define s second
#define INF 1e18;
#define NINF -1e18;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
void permutations(int cb,int tb,vector<int>&arr,int ssf,int sel,string output){
	if(cb>tb){
		if(ssf==sel){
			cout<<output<<endl;
		}
		return;
	}
	for(int i=0;i<(int)arr.size();i++){
		if(arr[i]==0){
			arr[i]=1;
			permutations(cb+1,tb,arr,ssf+1,sel,output+to_string(i+1));
			arr[i]=0;
		}
	}
	permutations(cb+1,tb,arr,ssf,sel,output+"0");
}
int main()
{
    IOS;
    int nbox,sel;
    cin>>nbox>>sel;
    vector<int>arr(sel,0);    
    permutations(1,nbox,arr,0,sel,"");
    return 0;
}
