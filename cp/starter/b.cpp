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
int main()
{
    IOS;
 	int t;
 	cin>>t;
 	while(t--){
 		int n,num,X,Y;
 		cin>>n>>num;
 		cin>>X>>Y;
 		string ouptut="";
 		for(int i=0;i<n;i++){
 			string s;
 			cin>>s;
 			int fcount=0;
 			int pcount=0;
 			for(int i=0;i<s.length();i++){
 				if(s[i]=='F'){
 					fcount++;
 				}else if(s[i]=='P'){
 					pcount++;
 				}
 			}
 			if(fcount>=X||(fcount==X-1&&pcount>=Y)){
 				ouptut+='1';
 			}else{
 				ouptut+='0';
 			}

 		}
 		cout<<ouptut<<endl;
 	}   
    return 0;
}