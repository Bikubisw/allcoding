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
void solution(int i,int k,int n,vector<vector<int>>&arr,int ssf){
	if(i>n){
		if(ssf==k){
			for(int i=0;i<k;i++){
				cout<<"[";
				for(int j=0;j<(int)arr[i].size();j++){
					cout<<arr[i][j]<<",";
				}
				cout<<"] ";
			}
			cout<<endl;
		}
		return;
	}
	
	for(int j=0;j<k;j++){
		if(arr[j].size()!=0){
			arr[j].push_back(i);
			solution(i+1,k,n,arr,ssf);
			arr[j].pop_back();
		}else{
			arr[j].push_back(i);
			solution(i+1,k,n,arr,ssf+1);
			arr[j].pop_back();
			break;
		}
	}
}
int main()
{
    IOS;
    int n,k;
    cin>>n>>k;
    vector<vector<int>>arr(k);
    solution(1,k,n,arr,0);
	return 0;
}
