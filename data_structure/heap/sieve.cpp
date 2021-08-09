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
int main()
{
    IOS;
 	int n;
 	cin>>n;
 	vector<bool>sieve(n+1,true);
 	sieve[0]=false;
 	sieve[1]=false;
 	for(int i=0;i*i<=n;i++){
 		if(sieve[i]){
 			for(int j=i*i;j<=n;j+=i)sieve[j]=false;
 		}
 	}
 	int count=0;
 	for(int i=0;i<=n;i++)if(sieve[i])count++;
 	cout<<count<<endl;
    return 0;
}