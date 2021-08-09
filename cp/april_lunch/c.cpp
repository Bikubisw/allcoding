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
 		int l;
 		cin>>l;
 		string s;
 		cin>>s;
 		int count11=0;
 		int count1=0;
 		int count=0;
 		for(int i=0;i<s.length();i++){
 			if(s[i]=='1'){
 				count1++;
 			}
 		}
 		int ans=(count1*100)/l;
 		if(ans>=50){
 			cout<<"YES"<<endl;
 		}
 		else{
 			if(s[0]=='1'){
 				count++;
 			}
 			bool flag=false;
 			for(int i=1;i<s.length();i++){
 				if(s[i]=='1'){
 					count++;
 				}
 				int ans=(count*100)/(i+1);
 				if(ans>=50){
 					flag=true;
 					break;
 				}
 			}
 			if(flag)cout<<"YES"<<endl;
 			else cout<<"NO"<<endl;

 	} 
}
return 0;
}