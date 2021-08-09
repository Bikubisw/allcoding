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
 		int n,a,b;
 		cin>>n>>a>>b;
 		ll sar=0;
 		ll anu=0; 
 		while(n--){
 			string s;
 			cin>>s;
 			if(s[0]=='E'||s[0]=='Q'||s[0]=='U'||s[0]=='I'||s[0]=='N'||s[0]=='O'||s[0]=='X'){
 					sar+=a;
 				}else{
 					anu+=b;
 				}
 		}
 		if(anu==sar){
 			cout<<"DRAW"<<endl;
 		}else if(anu>sar){
 			cout<<"ANURADHA"<<endl;
 		}else{
 			cout<<"SARTHAK"<<endl;
 		}
 	}   




    return 0;
}