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
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int closestNumber(int n, int m)
{
    for(int i=n+1,j=n-1;i<=1e6&&j>=-1e6;i++,j--){
        if(i%m==0){
	return i;
        	}
        	if(j%m==0){
	return j;
    }
}
}
int main()
{
    IOS;
 	int n,m;
 	cin>>n>>m;

 	cout<<closestNumber(n,m)<<endl;



    return 0;
}