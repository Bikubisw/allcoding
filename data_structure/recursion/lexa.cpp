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
void dfs(int i,int n){
			if(i>n){
			return;
		}else{
		cout<<i<<endl;
		for(int j=0;j<n;j++){
		dfs((10*i)+j,n);
		}
	}
}
int main()
{
    IOS;
    int n;
    cin>>n;
    //function<void (int,int)>dfs=[&](int i,int n){
		//if(i>n){
			//return;
		//}else{
		//cout<<i<<endl;
		//for(int j=0;j<n;j++){
		//dfs(10*i+j,n);
		//}
	//}
	//};
    for(int i=1;i<=9;i++){
		dfs(i,n);
	}
    return 0;
}
