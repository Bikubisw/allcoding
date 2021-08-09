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
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
#define MOD 1000000007
#define PINF LLONG_MAX
#define NINF LLONG_MIN
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main()
{
    IOS;
 	int t;
 	cin>>t;
 	while(t--){
 		int h,x,y,c;
 		cin>>h>>x>>y>>c;
 		int ans=h*(x+(y/2));
 		if(ans<=c){
 			cout<<"YES"<<endl;
 		}else cout<<"NO"<<endl;
 	}   




    return 0;
}